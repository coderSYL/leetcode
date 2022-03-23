// C++
// leetcode 1239
// https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// 思路:
// 二进制遍历

class Solution {
public:
	bool isGoodWord(string a)
	{
		for(int i = a.size()-1; i>=0; i--)	if(a.find(a[i]) != i) return false;
		return true;
	}

    int maxLength(vector<string>& arr) {
    	int size = arr.size();
    	int A_IN_ASCII = (int)'a';
    	for(int i = size-1; i>=0; i--)
    	{
    		if(!isGoodWord(arr[i]))
    		{
    			arr.erase( arr.begin()+i);
    			size--;
    		}
    	}	// delete bad words
    	int res = 0;
    	for(int i = 0; i < (1<<size); i++)
    	{
    		int f[26] = {0};
    		bool ok = true;
    		for(int j = 0; j < size; j++)
    		{
    			if( (1 << j) & i )
    			{
    				for(char c : arr[j])
    				{
    					f[(int)c - A_IN_ASCII]++;
    					if( f[(int)c - A_IN_ASCII] > 1)
    					{
    						ok = false;
    						break;
    					}
    				}
    			}
    			if(!ok)	break;
    		}
    		if(ok)	res = max (res, accumulate(f, f+26, 0));
    	}	// end all
    	return res;
    }
};