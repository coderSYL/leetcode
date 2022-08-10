// C++
// leetcode 640
// https://leetcode.cn/problems/solve-the-equation/

#include <string>

class Solution {
public:
	bool isNumber(char c) {
		if (c >= '0' && c <= '9')
			return true;
		return false;
	}

    string solveEquation(string s) {
    	int x_cnt = 0, val = 0, n = s.size();
    	bool after_equal = false;

    	for (int i = 0, j = 0; i < n; ) {
    		if (s[i] == '=') {
				after_equal = true;
				i++;
				continue;
    		}

    		int cur = 1;
    		if (s[i] == '-') {
    			cur = -1;
    			i++;
    		} else if (s[i] == '+') {
    			i++;
    		}

    		j = i;
    		while (j < n && isNumber(s[j]))
    			j++;
    		if (i != j)
    			cur *= stoi(s.substr(i, j - i));

    		if (s[j] == 'x') {
    			j++;
    			if (after_equal) {
    				x_cnt -= cur;
    			} else {
    				x_cnt += cur;
    			}
    		} else {
    			if (after_equal) {
    				val += cur;
    			} else {
    				val -= cur;
    			}
    		}
    		i = j;
    	}

    	if (x_cnt == 0) {
    		if (val == 0)
    			return "Infinite solutions";
    		else
    			return "No solution";
    	}
        
    	return "x=" + to_string(val / x_cnt);
    }
};