// C++
// leetcode 2385
// https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/

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

	const static int N = 100009, M = 200009;
	int he[N];
	int e[M], ne[M];
	int idx = 0;
	void initMap() {
		memset(he, -1, sizeof(he));
	}

	void add(int a, int b) {
		e[idx] = b;
		ne[idx] = he[a];
		he[a] = idx++;
	}

	void add2(int a, int b) {
		add(a, b);
		add(b, a);
	}

    int amountOfTime(TreeNode* root, int start) {
        initMap();
        map<TreeNode*, int> m;
        int n = 0;
        m[root] = n++;

        queue<TreeNode*> q;
        q.push(root);
        queue<int> qq;
        TreeNode *tmp;
        // 将树变成图
        while (!q.empty()) {
        	tmp = q.front();
        	q.pop();
        	int cur = m[tmp];
        	if (tmp -> val == start)
        		qq.push(cur);
        	if (tmp -> left) {
        		add2(cur, n);
        		m[tmp -> left] = n++;
        		q.push(tmp -> left);
        	}
        	if (tmp -> right) {
        		add2(cur, n);
        		m[tmp -> right] = n++;
        		q.push(tmp -> right);
        	}
        }


        if (n == qq.size())
        	return 0;

        // 模拟传染过程
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        int time = 0;
        int infected = 0;
        while(infected != n) {
        	int size = qq.size();
        	bool outCount = time == 0;
        	while(size--) {
        		int cur = qq.front();
        		qq.pop();
        		if (outCount) {
        			infected++;
        			vis[cur] = true;
        		}

        		for (int i = he[cur]; i != -1; i = ne[i]) {
        			int nextNode = e[i];
        			if (vis[nextNode])
        				continue;
        			qq.push(nextNode);
        			infected++;
        			vis[nextNode] = true;
        		}
        	}
        	time++;
        }

        return time;
    }
};