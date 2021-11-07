// C++
// leetcode 93
// https://leetcode-cn.com/problems/restore-ip-addresses/
// dfs


class Solution {
public:
	vector<string>	res;
	int n_;
	vector<char> v;
	string s_;

	void dfs(int done, int cur, int dot_num) {
		// 保证每个函数开始前，都是合规的
		if(done == n_) {
			if(dot_num == 3)
				res.push_back(string(v.begin(), v.end()));
			return;
		}

		char now = s_[done];
		int u = now - '0';


		// 两种操作，一种不加点
		// 先尝试不加点的，条件有：1. cur != 0    2. 加了后不超过255
		if(cur != 0) {
			int next = (cur == -1 ? 0 : cur) * 10 + u;
			if(next < 256) {
				// 可以搞
				v.push_back(now);
				dfs(done + 1, next, dot_num);
				v.pop_back();
			}
		}

		// 另一种操作，先加点，条件：1. cur != -1 , -1代表开头，开头不能直接加点 2. 目前已加点的个数小于3
		if(cur != -1 && dot_num < 3) {
			// 刚加完点后cur = -1，所以加点要求cur != -1
			v.push_back('.');
			v.push_back(now);
			dfs(done + 1, u, dot_num + 1);
			v.pop_back();
			v.pop_back();
		}
	}

    vector<string> restoreIpAddresses(string s) {
    	n_ = s.size();
    	s_ = s;
    	dfs(0, -1, 0);
    	return	res;
    }
};