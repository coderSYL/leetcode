// C++
// leetcode 1796
// https://leetcode.cn/problems/second-largest-digit-in-a-string/

class Solution {
public:
    int secondHighest(string s) {
    	bool ok[10];
    	memset(ok, 0, sizeof(ok));
    	for (auto c : s) {
    		int u = c - '0';
    		if (u > 10 || u < 0)
    			continue;
    		ok[u] = true;
    	}
    	int cnt = 0;
    	for (int i = 9; i >= 0; i--) {
    		if(ok[i])
    			cnt++;
    		if (cnt == 2)
    			return i;
    	}
    	return -1;
    }
};