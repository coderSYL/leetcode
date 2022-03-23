// C++
// leetcode 214
// https://leetcode-cn.com/problems/shortest-palindrome/
// 时间不太好

class Solution {
public:
    string shortestPalindrome(string s) {
    	int n = s.size();
    	if(n == 0) return s;
    	int i = n / 2, j = (n + 1) / 2;
    	bool good = false;
    	while(!good && i >= 0) {
            // cout<<"looping"<<endl;
    		int x = i, y = j;
    		while(x >= 0) {
    			if(s[x] == s[y]) {
    				x--;
    				y++;
    			} else {
    				break;
    			}
    		}
    		if(x == -1) {
    			good = true;
    		} else {
    			if(i == j) {
    				i--;
    			} else {
    				j--;
    			}
    		}
    	}
    	int end = i + j + 1;
    	if(end == n) return s;
    	vector<char> tmp(n - end);
    	for(int x = n - 1; x >= end; x--)
    		tmp[n - 1 -x] = s[x];
    	return string(tmp.begin(), tmp.end()) + s;
    }
};