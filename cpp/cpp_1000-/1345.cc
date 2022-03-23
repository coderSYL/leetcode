// C++
// leetcode 1345
// https://leetcode-cn.com/problems/jump-game-iv/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        q.push(0);
        vector<int> step(n, INT_MAX);
        step[0] = 0;
        // 预处理，把具有相同arr[i]的i都存进同一个数组里
        unordered_map<int, vector<int>> getRelated;
        for(int i = n - 1; i >= 0; i--) {
            getRelated[arr[i]].push_back(i);
        }

        while(!q.empty()) {
            int size = q.size();
            int fill = step[q.front()] + 1;
            while(size--) {
                int idx = q.front();
                q.pop();
                for(auto& x : getRelated[arr[idx]]) {
                    if(step[x] == INT_MAX) {
                        step[x] = fill;
                        q.push(x);
                    }
                }
                getRelated[arr[idx]].clear();
                if(idx - 1 >= 0 && step[idx - 1] == INT_MAX) {
                    step[idx - 1] = fill;
                    q.push(idx-1);
                }
                if(idx + 1 < n && step[idx + 1] == INT_MAX) {
                    step[idx + 1] = fill;
                    q.push(idx+1);
                }
            }
            if(step[n-1] < INT_MAX) return step[n-1];
        }
        return -1;  // never
    }
};