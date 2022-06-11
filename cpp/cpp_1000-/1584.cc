// C++
// leetcode 1584
// https://leetcode.cn/problems/min-cost-to-connect-all-points/

class Solution {
public:
	int get_h_distance(int x1, int y1, int x2, int y2) {
		return (x1 > x2 ? x1-x2 : x2-x1) + (y1 > y2 ? y1-y2 : y2-y1);
	}
	
    int minCostConnectPoints(vector<vector<int>>& pts) {
    	int n = pts.size();
    	int cost[n];
    	bool vis[n];
    	memset(cost, 1, sizeof(cost));
    	memset(vis, 0, sizeof(vis));
    	int cnt = 0;
    	int res = 0;
    	int next = 0;
    	while(++cnt < n) {
    		int cur = next, x = pts[cur][0], y = pts[cur][1];
    		vis[cur] = true;
    		int tmp = INT_MAX;
    		for(int i = 0; i < n; i++) {
    			if(vis[i])
    				continue;
    			cost[i] = min(cost[i], get_h_distance(pts[i][0], pts[i][1], x, y));
    			if(cost[i] < tmp) {
    				tmp = cost[i];
    				next = i;
    			}
    		}
    		res += cost[next];
    	}
    	return res;
    }
};