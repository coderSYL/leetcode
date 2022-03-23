// C++
// leetcode 743
// https://leetcode-cn.com/problems/network-delay-time/
// 迪杰斯特拉 Dijkstra

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< vector<int> >   time(n + 1, vector<int>(n+1, INT_MAX));
        vector<int> dist(n + 1, INT_MAX);
        vector<int> pre(n + 1, 0);
        set<int>    undone;
        for(int i = 1; i <= n; ++i) {
            undone.insert(i);
        }
        dist[k] = 0;
        pre[k] = k;
        // 把 times 优化一下，装进map
        
        for(auto tri : times) {
            time[ tri[0] ][ tri[1] ] = tri[2];
        }
        int res = -1;
        int next = k;
        int doneNum = 1;
        while(doneNum < n) {
            // 每轮确定一个点
            undone.erase(next);
            {
                // 先把上一个点能刷的刷了
                auto it = undone.begin();
                while(it != undone.end()) {
                    int one = *it;
                    ++it;
                    int newD = time[next][one];
                    if(newD == INT_MAX)
                        continue;
                    newD += dist[next];
                    if(newD < dist[one]) {
                        dist[one] = newD;
                        pre[one] = next;
                    }
                }
                // 刷完了
            }
            int m_loop = INT_MAX;
            {
                // 找下一个点
                auto it = undone.begin();
                while(it != undone.end()) {
                    int one = *it;
                    ++it;
                    if(dist[one] < m_loop) {
                        m_loop = dist[one];
                        next = one;
                    }
                }
            }
            if(m_loop == INT_MAX)
                return  -1;
            if(m_loop > res)
                res = m_loop;
            ++doneNum;
        }
        return  res;
    }
};