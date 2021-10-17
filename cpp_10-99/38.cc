// C++
// leetcode 38
// https://leetcode-cn.com/problems/count-and-say/
// 思路:
// s记录当前值，分析s得到两个数组，一个记录值，一个记录数量
// 根据两个数组刷新s的值，如此总共反复(n - 1)次得到最终答案

class Solution {
public:
	int char2int(char c) {	return	(int)c - 48;}
	
	string int2string(int a){   return string(1, (char)(a + 48));}

    string countAndSay(int n) {
    	string s = "1";
    	int len = 0;
    	int next = 0;
    	int temp = 0;
    	int temp_num = 0;


    	while(n > 1)	// 每个循环：根据已有string得到下一个string
    	{
    		len = s.size();
    		int num[len];
    		int count[len];
    		next = 0;
    		temp = char2int(s[0]);
    		temp_num = 0;
    		for(auto c : s)
    		{
    			if(char2int(c) == temp)
                    temp_num++;
    			else {
    				num[next] = temp;
    				count[next] = temp_num;
    				next++;
    				temp = char2int(c);
    				temp_num = 1;
    			}
    		}
			num[next] = temp;
			count[next] = temp_num;
			next++;
			s = "";
			for(int j = 0; j < next; j++)
                s += to_string(count[j]) + int2string(num[j]);
			n--;
    	}


    	return s;
    }
};