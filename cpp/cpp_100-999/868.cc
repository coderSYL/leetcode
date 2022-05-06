// C++
// leetcode 868
// https://leetcode-cn.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int n) {
    	int res = 0;
    	int pre = 1000, cur = 0;
    	while(n) {
    		if(n&1) {
    			res = max(res, cur-pre);
    			pre = cur;
    		}
    		n>>=1;
    		cur++;
    	}
    	return res;
    }
};