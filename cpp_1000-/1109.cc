// C++
// leetcode 1109
// https://leetcode-cn.com/problems/corporate-flight-bookings/
// 不知道叫啥方法，之前做过类似的思路

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    	vector<int>	res(n, 0);
    	for(auto p : bookings) {
    		res[p[0] - 1] += p[2];
    		if(p[1] != n)
    			res[p[1]] -= p[2];
    	}
    	for(int i = 1 ; i < n; i++) {
    		res[i] += res[i - 1];
    	}
    	return	res;
    }
};