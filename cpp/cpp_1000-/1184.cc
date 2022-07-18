// C++
// leetcode 1184
// https://leetcode.cn/problems/distance-between-bus-stops/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    	if (start == destination)
    		return 0;
    	if (start > destination)
    		swap(start, destination);

    	int sum = 0, cur = 0;
    	for (int i = 0; i < distance.size(); i++) {
    		sum += distance[i];
    		if (i >= start && i < destination)
    			cur += distance[i];
    	}
    	return min(cur, sum - cur);
    }
};