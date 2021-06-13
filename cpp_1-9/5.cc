/*
 * C++
 * leetcode 5
 * url: https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 用起始index和长度来记录答案
 * 以每个index和它后面的间隙作为中心来算这个中心能扩张的最大回文长度
 * 如果大于答案的长度，则刷新答案的长度和起始index
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int size =s.size();
		int left_global = 0;
		int max_global = 0, i=0,j =0;
        for(int index =0; index<size; index++){
        	// 1st situation
        	i =index;
        	j =i;
			while(i>=0 && j<size && s[i]==s[j]){
				i--;
				j++;
			}
			if(j-i-1>max_global){
				max_global = j-i-1;
				left_global = i+1;
			}
			if(j-i-1>max_global){
				max_global = j-i-1;
				left_global = i+1;
			}
			// 2nd situation
			if(index+1==size)
				continue;
			i =index;
        	j =i+1;
			while(i>=0 && j<size && s[i]==s[j]){
				i--;
				j++;
			}
			if(j-i-1>max_global){
				max_global = j-i-1;
				left_global = i+1;
			}
        }
        return s.substr(left_global, max_global);
    }
};
