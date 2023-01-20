// C++
// leetcode 1806
// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution {
public:
    int reinitializePermutation(int n) {
    	if (n == 2)
    		return 1;

    	int cnt = 0, idx = 1;
    	while(idx != 1 || cnt == 0) {
    		if (idx < n/2)
    			idx *= 2;
    		else
    			idx = (idx - n/2) * 2 + 1;
    		cnt++;
    	}
    	return cnt;
    }
};