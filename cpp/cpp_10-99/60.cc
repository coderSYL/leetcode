// C++
// leetcode 60
// https://leetcode-cn.com/problems/permutation-sequence/
// 


class Solution {
public:
	void swap(char* c, int a, int b) {
		// c[a + b] 的值移到 c[a] 的位置上
		// c[a] 到 c[a + b - 1] 全都向右平移一格
		if(b == 0)
			return;
		char tmp = c[a + b];
		for(int i = b; i > 0; i--)
			c[a + i] = c[a + i - 1];
		c[a] = tmp; 
	}

    string getPermutation(int n, int k) {
    	char c[n];
    	for(int i = 0; i < n; i++)
    		c[i] = '1' + i;

    	int base = 1;
    	for(int i = 1; i <= n; i++)
    		base *= i;
        k--;
    	for(int i = 0; i < n; i++) {
            base /= n - i;
    		int b = k / base;
    		swap(c, i, b);
    		k %= base;
    	}

    	return	string(c, c + n);
    }
};