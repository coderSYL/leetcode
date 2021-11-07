// C++
// leetcode 52
// https://leetcode-cn.com/problems/n-queens-ii/
// 改自51


class Solution {
public:
	int n_;
	vector<bool>	canNot;	// false表示没被占，能取
	vector<int>	cur;
	int res;

	void setTrue(int u) {
		if(u < 0 || u >= n_)
			return;
		canNot[u] = true;
	}

	void updateCanNotUsed() {
		for(int i = 0; i < n_; i++)
			canNot[i] = false;

		int cur_size = cur.size();
		for(int i = 0; i < cur_size; i++) {
			setTrue(cur[i]);
			setTrue(cur[i] + cur_size - i);
			setTrue(cur[i] - cur_size + i);
		}
	}

	void dfs(int done) {
		if(done == n_) {
			res++;
			return;
		}
		updateCanNotUsed();
		vector<bool>	canNot_local(canNot);
		for(int i = 0; i < n_; i++) {
			if(canNot_local[i])
				continue;
			// 可以
			cur.push_back(i);
			dfs(done + 1);
			cur.pop_back();
		}
	}

    int totalNQueens(int n) {
    	n_ = n;
    	canNot.resize(n_, false);
    	dfs(0);
    	return	res;
    }
};