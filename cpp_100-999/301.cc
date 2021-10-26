// C++
// leetcode 301
// https://leetcode-cn.com/problems/remove-invalid-parentheses/
// 一些trick，利用score_来剪枝
// 利用vector<char>代替string作为中间态以节省字符串运算的时间和空间


class Solution {
public:
	int max_;
	int max_len_tmp = 0;
	vector<char> cur_;
	int score_ = 0;

    vector<string> removeInvalidParentheses(string s) {
    	// 设定max_
    	int l_num = 0, r_num = 0;
    	for(char c : s) {
    		if(c == '(')
    			l_num++;
    		else if(c == ')')
    			r_num++;
    	}
    	max_ = min(l_num, r_num);

    	set<string>	set_res;
    	dfs(s, 0, set_res);

    	return	vector<string>(set_res.begin(), set_res.end());
    }


    void dfs(string& s, int u, set<string>&	res) {
    	if(u == s.size()) {
    		if(score_ == 0) {
    			if(cur_.size() > max_len_tmp) {
    				max_len_tmp = cur_.size();
    				res.clear();
    			}
    			if(cur_.size() == max_len_tmp) {
    				res.insert(string(cur_.begin(), cur_.end() ));
    			}
    		}
    		return;
    	}

    	if(s[u] == '(') {
    		// 左括号情况
    		if(score_ + 1 <= max_) {
    			cur_.push_back(s[u]);
    			score_++;
    			dfs(s, u + 1, res);
    			cur_.pop_back();
    			score_--;
    		}
    		dfs(s, u + 1, res);
    	} else if(s[u] == ')') {
    		// 右括号情况
    		if(score_ > 0) {
    			cur_.push_back(s[u]);
    			score_--;
    			dfs(s, u + 1, res);
    			score_++;
    			cur_.pop_back();
    		}
    		dfs(s, u + 1, res);
    	} else {
    		// 其他情况
    		cur_.push_back(s[u]);
    		dfs(s, u + 1, res);
    		cur_.pop_back();
    	}
    }
};