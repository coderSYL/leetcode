// C++
// leetcode 202
// https://leetcode-cn.com/problems/happy-number/

class Solution {
public:
	set<int> ok;
    bool isHappy(int n) {
    	int next = 0;
    	while(n > 0) {
    		int end = n % 10;
    		n /= 10;
    		next += end * end;
    	}

    	if(next == 1) return true;

    	if(ok.find(next) == ok.end()) {
    		ok.insert(next);
    	} else {
    		return false;
    	}

    	return isHappy(next);
    }
};