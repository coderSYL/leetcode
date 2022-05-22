// C++
// leetcode 464
// https://leetcode.cn/problems/can-i-win/

class Solution {
public:
	int max_value_;

	bool dfs(vector<int> &f, int state, int cur_sum, int target) {
		// already calculated
		if(f[state] != -1)
			return f[state];
		for(int i = 0, p = 1; i < max_value_; ++i, p <<= 1) {
			// already chosen before
			if(p & state)
				continue;
			// can reach the target
			if(cur_sum + i + 1 >= target || !dfs(f, state|p, cur_sum+i+1, target))
				return f[state] = 1;
		}
		return f[state] = 0;
	}

    bool canIWin(int max_value, int target) {
    	// one turn win
    	if(target <= max_value)
    		return true;
    	// can never reach target
    	if(max_value * (1 + max_value) / 2 < target)
    		return false;
    	// set value for max_value_
    	max_value_ = max_value;

    	vector<int> f(1 << max_value, -1);
    	return dfs(f, 0, 0, target);
    }
};