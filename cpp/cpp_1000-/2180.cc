// C++
// leetcode 2180
// https://leetcode.cn/problems/count-integers-with-even-digit-sum/

class Solution {
public:
	int countSum(int x) {
		int res = 0;
		while(x) {
			res += x % 10;
			x /= 10;
		}
		return res;
	}
	
    int countEven(int num) {
    	int cnt = 0;
        while(num > 0) {
        	int x = countSum(num--);
        	if ((x & 1) == 0)
        		cnt++;
        }
        return cnt;
    }
};