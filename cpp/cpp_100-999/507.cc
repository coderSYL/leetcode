// C++
// leetcode 507
// https://leetcode-cn.com/problems/perfect-number/
// 比较笨的枚举法

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
    	int sum = 1;
    	int l = 2;
    	while(l < num) {
    		if(num % l != 0) {
    			l++;
    			continue;
    		}
    		int r = num / l;
    		if(l >= r) {
    			if(l == r) sum += l;
    			break;
    		}
    		sum += l + r;
    		l++;
    	}
    	if(sum == num) return true;
    	return false;
    }
};