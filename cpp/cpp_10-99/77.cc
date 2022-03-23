// C++
// leetcode 77
// https://leetcode-cn.com/problems/combinations/

class Solution {
public:
	vector<vector<int>>	res;
	vector<int> v;
	int n_, k_;

	// cur 表示这次dfs要处理的数字
	// idx 表示 v 中现存有效数字的个数，以及下一个填充数字的index
	void dfs(int cur, int idx) {
		// 填满了，加入 res 中
		if(idx == k_) {
			res.push_back(v);
			return;
		}
		// 越界，返回
		if(cur == n_ + 1)	return;
		// 填充数字
		v[idx] = cur;
		dfs(cur + 1, idx + 1);
		dfs(cur + 1, idx);
	}

    vector<vector<int>> combine(int n, int k) {
    	n_ = n;
    	k_ = k;
    	// 一次性分配好然后填充，避免v的size反复变化造成内存分配时的时间消耗
    	v.resize(k);
    	dfs(1, 0);
       	return	res;
    }
};