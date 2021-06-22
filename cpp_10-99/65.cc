// C++
// leetcode 65
// https://leetcode-cn.com/problems/valid-number/
// 思路:
// 逐个分析判断每个字符
// canBeASymbol用法
	// 初始为true
	// 当出现+-时，需要canBeASymbol为true才予以通过，否则直接false
	// 遇上数字、小数点和符号 ->false
	// 遇上E e ->true
// NumAppear用法
	// 初始为false
	// 遇上数字->true
	// 遇上E e，若为false，返回false，若为true，置其为false
// eCounter计算e与E的数量
// pointCounter计算小数点的数量


class Solution {
public:
    bool isNumber(string s)
    {
    	bool canBeASymbol = true;
    	int pointCounter =0;
    	int eCounter = 0;
    	int NumAppear = false;
    	for(char c:s)
    	{
    		switch(c)
    		{
    			case '+':
    			case '-':
    				{
    					if(canBeASymbol)
    					{
    						canBeASymbol = false;
    					}
    					else
    					{
    						return false;
    					}
    					break;
    				}
    			case '1':
    			case '2':
    			case '3':
    			case '4':
    			case '5':
    			case '6':
    			case '7':
    			case '8':
    			case '9':
    			case '0':
    				{
    					canBeASymbol = false;
    					NumAppear = true;
    					break;
    				}
    			case 'e':
    			case 'E':
    				{
    					canBeASymbol = true;
    					eCounter++;
    					if(eCounter>1 || !NumAppear)
    						return false;
    					NumAppear = false;
    					break;
    				}
    			case '.':
    				{
    					canBeASymbol = false;
    					pointCounter++;
    					if(eCounter>0 || pointCounter>1)
    						return false;
    					break;
    				}
    			default:
    				return false;
    		}
    	}
    	return NumAppear;
    }
};