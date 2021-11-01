// C++
// leetcode 575
// https://leetcode-cn.com/problems/distribute-candies/
// 主要思路：求得candyType里有多少种类的值


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
    	sort(candyType.begin(), candyType.end());

    	int n = candyType.size();
    	int typeNum = 0;
    	int cur = INT_MAX;
    	for(auto x : candyType) {
    		if(x != cur) {
    			cur = x;
    			typeNum++;
    		}
    	}

    	return	min(n / 2, typeNum);
    }
};