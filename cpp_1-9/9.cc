/*
 * C++
 * leetcode9
 * url: https://leetcode-cn.com/problems/palindrome-number/
 * 如果是负的，直接false
 * 用一个长度为10的int数组来存储x的每一位数字
 * 然后用i,j两个指针夹击，判断
 */

class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)
			return false;
    	int temp[10], size =0;
    	while(x>0){
    		temp[size++] = x%10;
    		x = x/10;
    	}
    	int i =0, j= size-1;
    	while(i<j){
    		if(temp[i] != temp[j]){
    			return false;
    		}
			i++;
			j--;
    	}
    	return true;
    }
};