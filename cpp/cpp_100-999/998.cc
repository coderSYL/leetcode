// C++
// leetcode 998
// https://leetcode-cn.com/problems/maximum-binary-tree-ii/
// 怪题目，插入方法：
// 1. 若A为空，则返回val值的结点的指针
// 2. 1)若A非空，从右子树找下去，直到找到某个值大于val且右子树的值小于
// 	  	val的结点将新结点插入到右子树，新结点的左子树插上原先的右子树
// 	  2)若找不到这种右子树，则在最后一个结点的空的右子树上插入新结点

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
	TreeNode *toBeInserted;
	bool recursion(TreeNode* p, int a) {
		if(p->val < a)
			return false;
		if(p->right == nullptr) {
			p->right = toBeInserted;
			return true;
		}
		if(p->right->val < a) {
			TreeNode *tmp = p->right;
			p->right = toBeInserted;
			toBeInserted->left = tmp;
			return true;
		}
		return recursion(p->right, a);
	}

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    	toBeInserted = new TreeNode(val);
    	if(root == nullptr)
    		return toBeInserted;
    	if(root->val < val) {
    		toBeInserted->left = root;
    		return toBeInserted;
    	}
    	if(recursion(root, val))
    		return root;
    	return nullptr;
    }
};


// // 方法二
// class Solution {
// public:
// 	void putInVector(vector<int> &arr, TreeNode* root) {
// 		if (root == nullptr)
// 			return;

// 		putInVector(arr, root -> left);
// 		arr.push_back(root -> val);
// 		putInVector(arr, root -> right);
// 	}

// 	TreeNode* makeTreeFromVector(vector<int> &arr, int l, int r) {
// 		if (l > r)
// 			return nullptr;
// 		int p = r, mx = arr[r];
// 		for (int i = l; i < r; i++) {
// 			if (arr[i] > mx) {
// 				mx = arr[i];
// 				p = i;
// 			}
// 		}
// 		return new TreeNode(mx, makeTreeFromVector(arr, l, p - 1), makeTreeFromVector(arr, p + 1, r));
// 	}

//     TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
//     	vector<int> arr;
//     	putInVector(arr, root);
//     	arr.push_back(val);
//         return makeTreeFromVector(arr, 0, arr.size() - 1);
//     }
// };