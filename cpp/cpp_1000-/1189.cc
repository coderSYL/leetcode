// C++
// leetcode 1189
// https://leetcode-cn.com/problems/maximum-number-of-balloons/

class Solution {
public:
	int standard[26] = {0};
	string s = "balloon";
	int maxNumberOfBalloons(string text) {
		for (auto & c : s)
			standard[c - 'a']++;
		int cnt[26] = {0};
		for (auto &c : text) {
			cnt[c - 'a']++;
		}
		int res = INT_MAX;

		for (auto & c : s) {
			res = min(res, cnt[c - 'a'] / standard[c - 'a']);
		}
		return res;
	}
};