// C++
// leetcode 654
// https://leetcode.cn/problems/maximum-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int l, int r) {
    	if (l > r) {
    		return nullptr;
    	}

    	int mx = INT_MIN, p = -1;
    	for (int i = l; i <= r; i++) {
    		if (nums[i] > mx) {
    			mx = nums[i];
    			p = i;
    		}
    	}

    	TreeNode *res = new TreeNode(mx);
    	res -> left = helper(nums, l, p -1); 
    	res -> right = helper(nums, p + 1, r);
    	return res; 
    }
};