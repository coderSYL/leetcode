// C++
// leetcode 双周赛 2021-08-21
// https://leetcode-cn.com/contest/biweekly-contest-59/problems/number-of-ways-to-arrive-at-destination/
// 3

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long>    time(n, LONG_MAX);
        vector<long>    res(n, 0);
        time[0] = 0;
        res[0] = 1;
        vector<bool>    arrived(n, false);
        arrived[0] = true;

        // 把路径数据存到map里
        map<int, set< pair<int ,int> > >   m; // < 出发点， set <到达点， 所花费的时间>>
        for(auto oneRoad : roads) {
            int start = oneRoad[0], end = oneRoad[1], tt = oneRoad[2];
            m[start].insert( make_pair(end, tt));
            m[end].insert( make_pair(start, tt));
        }
        for(auto it = m[0].begin() ; it != m[0].end(); it++) {
            int to = (*it).first;
            long ttime = (*it).second;
            time[ to ] = ttime;
            res[to] = 1;
        }


        while(!arrived[n - 1]) {
            // 每个循环找到一个没去过的，最短的，标记为去过，然后再把它能去的路口给刷新了
            int goalForThisLoop = -1;
            long timeTaken = LONG_MAX;
            for(int i = 0; i < n; i++) {
                if(arrived[i])  continue;
                if(time[i] < timeTaken) {
                    // 好像有个隐忧，就是如果两个一样大，哦没问题，想多了
                    goalForThisLoop = i;
                    timeTaken = time[i];
                }
            }
            if(goalForThisLoop == -1)
                return  -1; // 到达不了n - 1
            arrived[goalForThisLoop] = true;
            for(auto it = m[goalForThisLoop].begin(); it != m[goalForThisLoop].end(); it++) {
                int to = (*it).first;
                long ttime = timeTaken + (*it).second;
                if(time[to] == ttime) {
                    res[to] = (res[to] + res[goalForThisLoop])%1000000007;
                } else if(time[to] > ttime) {
                    time[to] = ttime;
                    res[to] = res[goalForThisLoop];
                }
            }
        }
        return  int(res[n - 1]);
    }
};