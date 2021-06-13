/**
 * C++
 * leetcode 13
 * url: https://leetcode-cn.com/problems/roman-to-integer/
 * 找到字符串中最大的字母和数量，然后把字符串分成三份，中间 +右边 -左边
 */

class Solution {
public:
    int romanToInt(string s) {
    	int size = s.size(), i=0;
    	if(size ==0)
    		return 0;
    	int values[7]={1000,500,100,50,10,5,1};
        char reps[7]={'M','D','C','L','X','V','I'};
        for(int k =0; k<7; k++){
	        int startPoint = -1, counter = 0;
	        for(i =0; i<size; i++){
	        	if(s[i] == reps[k]){
	        		counter++;
	        		if(startPoint==-1)
	        			startPoint = i;
	        	}else if(counter>0)
	        		break;
	        }
	        if(counter>0){
	        	string left, right;
	        	if(startPoint!=0)
	        		left = s.substr(0, startPoint);
	        	if(startPoint+counter != size)
	        		right = s.substr(startPoint+counter);
	        	return counter*values[k]-(romanToInt(left))+(romanToInt(right));
	        }
	    }
	    return 0;
    }
};