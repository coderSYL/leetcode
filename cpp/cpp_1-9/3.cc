/*
 * C++
 * leetcode 3
 * url: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * 用p一次遍历
 * 一个int start用来记录当前字符串起点
 * 每次p判断流程：
 * 		用i遍历start到p-1，s[i]是否与s[p]相等
 *		* 存在相等的则用p-start与max_global相比，更大的话则刷新max_global，且更新start = 相等的i +1
 *		* 不存在相等的则可以不做任何事
 * 最后还需要用p-start刷一次max_global
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int size = s.size(), max_global =1;
    	if(size==0)
    		return 0;
    	int start = 0,p =1;
    	while(p<size){
    		for(int i =start; i<p; i++){
    			if(s[i] ==s[p]){
    				if(p-start>max_global)
    					max_global = p-start;
    				start =i+1;
    			}
    		}
    		p++;
    	}
		if(p-start>max_global)
			max_global = p-start;
		return max_global;
    }
};