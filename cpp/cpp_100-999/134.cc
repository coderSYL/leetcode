// C++
// leetcode 134
// https://leetcode.cn/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int n = gas.size(), res = 0, remain = 0, debt = 0;
    	for(int i = 0; i < n; ++i) {
    		remain += gas[i] - cost[i];
            // 如果剩下的小于0，则化为负债去到下一个加油站
    		if(remain < 0) {
                res = i + 1;
                debt += remain;
                remain = 0;
            }
    	}
        // 剩下的若不能还下负债则返回-1
    	return (remain + debt >= 0? res : -1);
    }
};