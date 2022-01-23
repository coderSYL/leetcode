// C++
// leetcode 539
// https://leetcode-cn.com/problems/minimum-time-difference/

class Solution {
public:
	int getIntFromString(string &s) {
		int h = stoi(s.substr(0,2));
		int min = stoi(s.substr(3,2));
		return h * 60 + min;
	}
    int findMinDifference(vector<string>& timePoints) {
    	if(timePoints.size() > 1440) return 0;
    	set<int> set;
    	for(auto &s : timePoints) {
    		int tmp = getIntFromString(s);
    		if(set.find(tmp) == set.end()) {
    			// 不存在，加进去
    			set.insert(tmp);
    			set.insert(tmp+1440);
    		} else {
    			return 0;
    		}
    	}
    	int pre = -1440;
    	int res = 1440;
    	for(auto &x : set) {
    		res = min(res, x - pre);
    		pre = x;
    		if(res == 1) return 1;
    	}
    	return res;
    }
};