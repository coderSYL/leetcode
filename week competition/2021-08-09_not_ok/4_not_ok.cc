// C++
// leetcode 周赛 2021-08-08
// https://leetcode-cn.com/contest/weekly-contest-253/problems/find-the-longest-valid-obstacle-course-at-each-position/
// 第四题

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    	int n = obstacles.size();
    	vector<int>	helper(10000000, 0);
    	vector<int> res(n);
    	res[0] = 1;
    	int l = obstacles[0];
    	int r = obstacles[0];
    	helper[l] = 1;
    	for(int i = 1; i < n; i++) {
    		int now = obstacles[i];

    		if(now < l) {
    			for(int j = l; j < l; j++) {
    				helper[j] = 1;
    			}
    			l = now;
    		} else if(now > r) {
    			int m = helper[r];
    			for(int j = r + 1; j < now; j++) {
    				helper[j] = m;
    			}
    			helper[now] = m + 1;
                r = now;
    		} else {
                helper[now]++;
                int nn = helper[now];
    			for(int j = now + 1; j <= r; j++) {
    				helper[j] = max(helper[j], nn);
    			}
    		}
    		
    		res[i] =helper[now];
    	}
    	return	res;
    }
};