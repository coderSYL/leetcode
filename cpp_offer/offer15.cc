// C++
// leetcode offer 15
// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
// 一枪起了，我秒了有什么好说的

class Solution {
public:
	bool isOdd(uint32_t n)	{	return (n % 2);}

    int hammingWeight(uint32_t n) {
    	int res = 0;
    	while(n>0)
    	{
    		if(isOdd(n))	res++;
    		n = n>>1;
    	}
    	return res;
    }
};