// C++
// leetcode 1450
// https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    	int n = startTime.size(), res = 0;
    	for (int i = 0; i < n; i++) {
    		if (startTime[i] <= queryTime && endTime[i] >= queryTime)
    			res++;
    	}
    	return res;
    }
};