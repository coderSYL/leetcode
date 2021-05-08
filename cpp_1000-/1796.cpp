/*
 * C++
 * leetcode1796
 * url: https://leetcode-cn.com/problems/second-largest-digit-in-a-string/
 */

class Solution {
public:
    int secondHighest(string s) {
    	int res = -1, max = -1, size = s.size(), temp =-1;
    	bool max_exist = false;
    	for(int i = 0; i<size; i++){
    		temp = (int)s[i]-48;
    		if( temp>=0 && temp<10){
    			if(!max_exist){	// 还没有max
    				max_exist = true;
    				max = temp;
    			}else{			// 有max
    				if(temp== max){
    					continue;
    				}else if(temp > max){
    					res = max;
    					max = temp;
    				}else if(temp>res)
    						res = temp;
    			}
    		}
    	}
    	return res;
    }
};