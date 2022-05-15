// C++
// leetcode interview 01.05
// https://leetcode.cn/problems/one-away-lcci/

class Solution {
public:
    bool oneEditAway(string first, string second) {
    	int n1 = first.size(), n2 = second.size();
    	if(n1 < n2) {
    		first.swap(second);
    		swap(n1, n2);
    	}
    	if(n1-n2 > 1)
    		return false;
    	if(n1 == n2) {
    		// 一样长
    		int cnt = 0;
    		for(int i = 0; i < n1; ++i) {
    			if(first[i] != second[i])
    				cnt++;
    			if(cnt > 1)
    				return false;
    		}
    	} else {
    		// first 长
    		for(int i = 0, j = 0; j < n2;) {
    			if(first[i] == second[j]) {
    				j++;
    			}
    			i++;
    			if(i - j > 1)
    				return false;
    		}
    	}
    	return true;
    }
};