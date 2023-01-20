// C++
// leetcode 904
// https://leetcode.cn/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fs) {
    	int n = fs.size(), res = 0, tot = 0;
    	int cnts[n+5];
    	memset(cnts, 0, sizeof(cnts));
    	for (int i = 0, j = 0; i < n; i++) {
    		if (++cnts[fs[i]] == 1)
    			tot++;
    		while(tot > 2) {
    			if(--cnts[fs[j++]] == 0)
    				tot--;
    		}
    		res = max(res, i - j + 1);
    	}
    	return res;
    }
};