// C++
// leetcode 565
// https://leetcode.cn/problems/array-nesting/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int cur = i, cnt = 0;
            while (nums[cur] != -1) {
                cnt++;
                int c = cur;
                cur = nums[cur];
                nums[c] = -1;
            }
            res = max(res, cnt);
        }
    	return res;
    }
};