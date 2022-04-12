// C++
// leetcode 2233
// https://leetcode-cn.com/problems/maximum-product-after-k-increments/

class Solution {
public:
	int MOD = (int)1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(k--) {
        	int x = pq.top();
        	pq.pop();
        	pq.push(x+1);
        }
        int res = 1;
        while(!pq.empty()) {
        	res *= pq.top();
        	pq.pop();
        	res %= MOD;
        }
        return res;
    }
};