// C++
// leetcode 127
// https://leetcode-cn.com/problems/word-ladder/
// 双向队列DFS

class Solution {
public:
    bool isGoodWord(string a, string b){
        // 若 a, b两个词刚好有一个字母不同，返回 true
        // 否则返回 false
        bool ok = true;
        for(int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if(ok)  ok = false;
                else return false;
            }
        }
        return !ok;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool endExist = false;
        for(auto x : wordList) {
            if(x == endWord) {
                endExist = true;
                break;
            }
        }
        if(!endExist)
            return  0;
        if(isGoodWord(beginWord, endWord))
            return  2;
        q_start.push(beginWord);
        q_end.push(endWord);
        canGetFromStart[beginWord] = 1;
        canGetFromEnd[endWord] = 1;

        while((!q_start.empty()) && (!q_end.empty())) {
            // 每轮找一个从头的，再找一个从尾的
            string temp = q_start.front();
            q_start.pop();
            int step = canGetFromStart[temp] + 1;
            for(auto s : wordList) {
                if (canGetFromStart.find(s) != canGetFromStart.end()) {
                    // 已经到过
                    continue;
                } else if (isGoodWord(s, temp)) {
                    // 好词
                    if(canGetFromEnd.find(s) != canGetFromEnd.end()) {
                        // 接通了
                        return  step + canGetFromEnd[s] - 1;
                    }
                    canGetFromStart[s] = step;
                    q_start.push(s);
                }
            }
            // 找一个从尾的
            temp = q_end.front();
            step = canGetFromEnd[temp] + 1;
            for(auto s : wordList) {
                if(canGetFromEnd.find(s) != canGetFromEnd.end()) {
                    continue;
                } else if(isGoodWord(s, temp)) {
                    if(canGetFromStart.find(s) != canGetFromStart.end()) {
                        // 接通了
                        return  step + canGetFromStart[s] - 1;
                    }
                    canGetFromEnd[s] = step;
                     q_end.push(s);
                }
            }
            q_end.pop();
        }
        return 0;
    }

private:
    unordered_map<string, int> canGetFromStart;
    unordered_map<string, int> canGetFromEnd;
    queue<string>   q_start;
    queue<string>   q_end;
};