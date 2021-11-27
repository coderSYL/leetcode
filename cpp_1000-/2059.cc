// C++
// leetcode 2059
// https://leetcode-cn.com/problems/minimum-operations-to-convert-number/

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visit(1001, false);
        queue<int>  q;
        visit[start] = true;
        q.push(start);
        int res = 0, done = 0;
        while(!q.empty()) {
            int size = q.size();
            res++;
            // 所有步数为 res - 1 的都要出队
            while(size--) {
                int cur = q.front();
                q.pop();
                for(auto x : nums) {
                    int next = cur - x;
                    if(next == goal) return  res;
                    if(next>= 0 && next <= 1000 && !visit[next]) {
                        q.push(next);
                        visit[next] = true;
                    }

                    next = cur + x;
                    if(next == goal) return  res;
                    if(next>= 0 && next <= 1000 && !visit[next]) {
                        q.push(next);
                        visit[next] = true;
                    }

                    next = cur ^ x;
                    if(next == goal) return  res;
                    if(next>= 0 && next <= 1000 && !visit[next]) {
                        q.push(next);
                        visit[next] = true;
                    }
                }
            }
            
        }
        return  -1;
    }
};