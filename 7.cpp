/*
 * C++
 * leetcode7
 * url: https://leetcode-cn.com/problems/reverse-integer/
 */

class Solution {
public:
    int reverse(int x) {
    	long res=0;
    	bool flag=false;
    	if(x == -2147483648)
    		return 0;
    	if(x<0){
    		x = -x;
    		flag = true;
    	}
    	while(x>0){
    		res = res*10+x%10;
    		x = x/10;
    	}
    	if(flag)
    		res = -res;
    	if(res<-2147483648 || res>2147483647)
    		return 0;
    	return (int)res;
    }
};