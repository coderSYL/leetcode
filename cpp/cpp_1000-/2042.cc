// C++
// leetcode 2042
// https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int last = 0, n = s.size(), cur = 0;
        for (int i = 0; i < n; i++) {
        	int u = s[i] - '0';
        	if (u < 10 && u >= 0) {
        		cur = cur * 10 + u;
        	} else {
        		if (cur == 0)
        			continue;
        		if (cur <= last) {
        			// cout<<"NOT OK for "<< cur << " <= "<<last<<endl;
        			return false;
        		}
        		else {
        			last = cur;
        			cur = 0;
        		}
        	}
        }
        if (cur != 0 && cur <= last)
        	return false;
        return true;
    }
};