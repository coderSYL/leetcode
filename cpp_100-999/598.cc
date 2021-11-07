// C++
// leetcode 598
// https://leetcode-cn.com/problems/range-addition-ii/
// 


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
    	int a = m, b = n;
    	for(auto x : ops) {
    		a = min(a, x[0]);
    		b = min(b, x[1]);
    	}
    	return a * b;
    }
};