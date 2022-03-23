// C++
// leetcode 483
// https://leetcode-cn.com/problems/smallest-good-base/
// 思路:
// 看了宫水三叶的，牛大了

typedef unsigned long long ull;

class Solution {
public:
    string smallestGoodBase(string n) {
    	ull num = stoll(n);
    	for( int m =log2(num) + 1; m>=3; m--)
    	{
			ull k = (ull) powl(num, 1.0 / (m - 1));
			ull temp = 0;
			for(int i = 0; i < m; i++)	temp = temp * k + 1;
			if(temp == num)	return to_string(k);
    	}
    	return to_string(num - 1);
    }
};