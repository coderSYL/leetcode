// C++
// leetcode 双周赛 2021-08-21
// https://leetcode-cn.com/contest/biweekly-contest-59/problems/minimum-time-to-type-word-using-special-typewriter/
// 1

class Solution {
public:
    int minTimeToType(string word) {
    	int last = 97;	// 初始为 'a'
    	int res = word.size();
    	for(auto c : word) {
    		int thisOne = (int) c;
    		int a = thisOne - last;
    		if(a < 0)	a = -a;
    		int b = 26 - a;
    		res += min(a, b);
    		last = thisOne;
    	}
    	return	res;
    }
};