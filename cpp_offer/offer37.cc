// C++
// leetcode offer 37
// https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
// 思路写在了注释里
#include <string>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	string res;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	res = "[";
        queue<TreeNode*> q;
        q.push(root);
        int good = 1;	// q 中前 good 个肯定是带数字的，后面如果全是 null 就不用再处理了，以免字符串结尾多出很多 null
        while(!q.empty() && good)
        {
        	TreeNode* temp = q.front();
        	q.pop();
        	--good;
        	if(res.back() != '[' && res.back() != ',')
        		res += ',';
        	if(temp == nullptr)
        		res += "null";
        	else
        	{
        		res += to_string( temp->val);
        		q.push(temp->left);
        		q.push(temp->right);
        		if(temp->right)
        			good = q.size();	// 刷新good
        		else if(temp->left)
        			good = q.size() - 1;
        	}
        }
        res += "]";
		return res;
    }


    inline bool isNull(int start) {
    	if(res[start] =='n')
    		return true;
    	return false;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	res = data;	// 让 res 与 data 挂钩
        int SIZE = data.size();
        int start = 1;
        int end = 2;
        TreeNode *root = nullptr;	// 将作为返回值
        queue<TreeNode*> q;			// 工作队列
        TreeNode *temp = nullptr;	// 正在被加左右子树的结点的指针
        bool leftUsed = false;		// 表示 temp 的左子树是否已经被用了		
        TreeNode *cur = nullptr;	// 指向从 string 中新鲜出炉的 TreeNode
        while(start < SIZE -1)
        {
        	while((res[end] != ',' && res[end] != ']')&& end !=SIZE)	end++;
        	// 根据要处理的字符串片段生成相应的Node
        	if(isNull(start))
        		cur = nullptr;	// 空的
        	else
        	{
        		// 有数字的情况
        		cur = new TreeNode( stoi(res.substr(start, end - start)));
        		q.push(cur);
        	}

        	// 如果还没有 root，先填 root 和 temp
        	if(root == nullptr)
        	{
        		if(cur == nullptr)	return nullptr;
        		root = cur;
        		temp = cur;
        		q.pop();
        		++end;
        		start = end;
        		continue;
        	}

        	
        	if(leftUsed)
        	{
        		// 左边被用过了，填充右子树，然后找到下一个 temp
        		temp -> right = cur;
        		temp = q.front();
        		q.pop();
        	}
        	else
        		// 左子树没被用过，填充左子树
        		temp ->left = cur;
        	leftUsed = !leftUsed;
        	++end;
        	start = end;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));