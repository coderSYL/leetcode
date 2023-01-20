// C++
// leetcode 1464
// https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int arr[2];
        memset(arr, 0, sizeof(arr));
    	for (auto x : nums) {
    		arr[1] = max(arr[1], arr[0] * (x - 1));
    		arr[0] = max(arr[0], x - 1);
    	}
    	return arr[1];
    }
};