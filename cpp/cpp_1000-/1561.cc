// C++
// leetcode 1561
// https://ssg.leetcode.cn/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
    	sort(piles.begin(), piles.end());
    	int n = piles.size(), res = 0, chances = n / 3;
    	do {
    		res += piles[n - 2 * chances];
    	} while (--chances);
    	return res;
    }
};