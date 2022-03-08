// C++
// leetcode 6
// https://leetcode-cn.com/problems/zigzag-conversion/
// 特殊情况，numRows = 1， 直接返回s
// 用numRows 个string来存分类的情况
// 再那些string模拟出返回值所需的那个string
 

class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows==1)
    		return s;
    	int ssize = s.size(), size = ssize/(2*numRows-2), tmp =0;
    	size = 2* (size+1);
    	// build string of numRows groups
    	char temp[numRows][size];
    	int p[numRows];
    	memset(p,0,sizeof(p));
    	int i = 0;
    	while(i<ssize){
    		for(int j=0; j<2*numRows-2; j++){
    			if(j<numRows){
    				tmp =j;
    			}else{
    				tmp = 2* numRows-2-j;
    			}
                
    			temp[tmp][p[tmp]] = s[i];
    			p[tmp]++;
                i++;
                if(i==ssize)
                    break;
    		}
    	}	// fill s into the string groups
    	char fake_ret[ssize+1];
    	int fake =0;
    	i=0;
    	// fill answer from the groups
    	while(i<numRows ){
    		int j =0;	// iterator for temp[i]
    		while(j<p[i]){
    			fake_ret[fake] = temp[i][j];
    			j++;
    			fake++;
    		}
    		i++;
    	}
    	fake_ret[ssize] = '\0';	//set end for the string
    	return fake_ret;
    }
};