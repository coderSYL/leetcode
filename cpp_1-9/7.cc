/*
 * C++
 * leetcode7
 * url: https://leetcode-cn.com/problems/reverse-integer/
 * 用long来存答案，如果最后越界了则返回0
 * 如果x是负数，把x弄成正数，flag记为true，最后依据flag将x调回负数
 * 每次薅掉x的最后一位，并加到res 的最后一位
 */

class Solution {
public:
    int reverse(int x) {
    	long res=0;
        long xx = (long)x;
    	bool flag=false;
    	if(xx<0){
    		xx = -xx;
    		flag = true;
    	}
    	while(xx>0){
    		res = res*10+xx%10;
    		xx = xx/10;
    	}
    	if(flag)
    		res = -res;
    	if(res<-2147483648 || res>2147483647)
    		return 0;
    	return (int)res;
    }
};