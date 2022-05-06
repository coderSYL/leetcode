// C++
// leetcode 666
// https://leetcode-cn.com/problems/path-sum-iv/

class Solution {
public:
	bool isLeafNode(vector<int> &tree, int node) {
		int n = tree.size();
		node *= 2;
		if(node < n && tree[node++] != -1)
			return false;
		if(node < n && tree[node++] != -1)
			return false;
		return true;
	}

    int pathSum(vector<int>& nums) {
    	vector<int> weightOf(16, -1);
    	for(auto &x : nums) {
    		int num = (1<<(x/100-1)) -1 + (x/10) % 10;
    		int weight = x % 10;
    		weightOf[num] = weight;
    	}
    	int res = 0;
    	for(int i = 1; i < 16; i++) {
    		if(weightOf[i] == -1)
    			continue;
    		if(i != 1)
    			weightOf[i] += weightOf[i/2];
    		if(isLeafNode(weightOf, i)) {
    			res += weightOf[i];
    		}
    	}
    	return res;
    }
};