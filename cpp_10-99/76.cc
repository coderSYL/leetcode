// C++
// leetcode 76
// https://leetcode-cn.com/problems/minimum-window-substring/
// 滑动窗口，一遍循环，每次右滑一位，并且看看左侧能不能收缩

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>  record; // 记录t中各字母的数目
        unordered_map<char, int>  work; // 工作map
        for(auto c : t) record[c]++;
        int t_size = t.size();
        int s_size = s.size();
        string  res;
        int cnt = 0;

        for(int i = 0, j = 0; j < s_size; j++) {
            char loop_c  = s[j];
            work[loop_c]++;
            if(work[loop_c] <= record[loop_c])
                cnt++;
            while(i <= j && work[s[i]] > record[s[i]]) {
                work[s[i]]--;
                i++;
            }
            if(cnt == t_size && (res.empty() || res.size() > j - i + 1))
                res = s.substr(i, j - i + 1);
        }
        return  res;
    }
};