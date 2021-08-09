// C++
// leetcode 周赛 2021-08-08
// https://leetcode-cn.com/contest/weekly-contest-253/problems/remove-stones-to-minimize-the-total/
// 第二题

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
    	priority_queue<int>	temp(piles.begin(), piles.end());
    	while(k > 0) {
    		int big = temp.top();
    		temp.pop();
    		temp.push((big + 1)/2);
    		k--;
    	}
    	int res = 0;
    	while(!temp.empty()) {
    		res += temp.top();
    		temp.pop();
    	}
    	return	res;
    }
};