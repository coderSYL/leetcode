// C++
// leetcode 877
// https://leetcode-cn.com/problems/stone-game/
// 思路:
// 必胜法
// 或者dp

// 必胜法
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) 
//     {
//     	return true;
//     }
// };

// dp
class Solution {
public:
    // return absolute(a-b)
	int positiveSubs(int a, int b)
	{
		if(a>b)
			return a-b;
		return b-a;
	}
    // return maximum of 3 numbers
	int maxFrom3(int a, int b, int c)
	{
		if(a<b)
		{	
			// a not ok
			if(b>c)
				return b;
			else
				return c;
		}
		else
		{
			// b not ok
			if(a>c)
				return a;
			else
				return c;
		}
		return 0;	// error
	}
    
    bool stoneGame(vector<int>& piles) 
    {
    	int size= piles.size();
    	int dp[size][size];
    	int i_val = piles[0], inext_val;
    	for(int i =0; i< size-1; i++)
    	{
    		inext_val = piles[i+1];
    		dp[i][i+1] = (inext_val >i_val)? (inext_val -i_val): (i_val -inext_val);
    		i_val = inext_val;
    	}
    	int cha =3;
    	int j = 0;
    	while(cha <size){
    		for(int i =0; i<size-cha; i++){
    			j = i+cha;
    			dp[i][j] = maxFrom3( dp[i][j-2]+dp[j-1][j], dp[i+1][j-1] +positiveSubs( piles[i], piles[j]), dp[i][i+1]+dp[i+2][j]);
    		}
    		cha +=2;
    	}
    	return dp[0][size-1]>0 ;
    }
};