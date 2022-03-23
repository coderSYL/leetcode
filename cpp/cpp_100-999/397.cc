// C++
// leetcode 397
// https://leetcode-cn.com/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(int n) {
    	// 特殊情况，可以算出来，但是计算过程int n会溢出
		if(n == INT_MAX)	return 32;
    	int res = 0;
    	// 每个循环一次操作
    	while(n != 1) {
    		if(n % 2 == 0) {
    			// 偶数，直接除二
    			n >>= 1;
    		} else {
    			// 奇数，如果可以消除之后的1，就+1
    			if (n != 3 && ((n >> 1) & 1) == 1)
    				n++;
    			else
    				n--;
    		}
    		res++;
    	}
    	return	res;
    }
};