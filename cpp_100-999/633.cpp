/*
 * C++
 * leetcode633
 * url: https://leetcode-cn.com/problems/sum-of-square-numbers/
 * 双指针i,j
 * i从0开始，j从sq(c)开始，为了减少计算，放低了sq的精度，使得sq(c)要在计算结果加100
 */
class Solution {
public:
	long Sq(int a){
		float f = (float)a;
		float res = f/2;
		while(abs(res*res-f)>10000)
			res = (res + f/res)/2;
		return (long)(res+100);
	}

    bool judgeSquareSum(int c) {
		long cc =(long)c;
    	long i = 0, j = Sq(c);
    	while(i<=j && i*i+j*j !=cc){
    		if(i*i+j*j >c)
    			j--;
    		if(i*i+j*j <c)
    			i++;
    	}
    	if(i*i+j*j == c)
    		return true;
    	return false;
    }
};