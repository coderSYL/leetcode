// C++
// leetcode 367
// https://leetcode-cn.com/problems/valid-perfect-square/
// 


class Solution {
public:
	int bar = 46340;	// bar * bar > INT_MAX, (bar - 1) ^ 2 < INT_MAX
    bool isPerfectSquare(int num) {
    	int l = 1, r = (num > 92679 ? 92679 : num);
    	while(l <= r) {
    		int mid = (r + l) / 2;
    		if(mid > bar)
    			return	false;
    		if(mid * mid > num) {
    			r = mid - 1;
    		} else if(mid * mid < num) {
    			l = mid + 1;
    		} else {
    			return	true;
    		}
    	}

    	return	false;
    }
};