// C++
// leetcode 871
// https://leetcode.cn/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    	if(startFuel >= target)
    		return 0;

    	int n = stations.size();
    	priority_queue<int> fuel;

    	for(int i = 0; i < n; i++) {
    		int x = stations[i][0];
    		while(startFuel < x) {
    			if(fuel.empty())
    				return -1;
    			startFuel += fuel.top();
    			fuel.pop();
    		}
    		fuel.push((stations[i][1]));
    	}

    	while (startFuel < target) {
    		if(fuel.empty())
				return -1;
			startFuel += fuel.top();
			fuel.pop();
    	}
    	return n - fuel.size();
    }
};