// C++
// leetcode 495
// https://leetcode-cn.com/problems/teemo-attacking/
// 简简单单一个遍历


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	int stop_time = INT_MIN;
    	int res = 0;
    	for(auto x : timeSeries) {
    		if(x >= stop_time)
    			res += duration;
    		else
    			res += duration - stop_time + x;
    		stop_time = x + duration;
    	}
    	return	res;
    }
};