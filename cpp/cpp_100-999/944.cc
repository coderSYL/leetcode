// C++
// leetcode 944
// https://leetcode.cn/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
    	int n = strs.size(), m = strs[0].size();
    	vector<char> tmp(m);
    	vector<bool> not_need_delete(m, true);
    	for(int i = 0; i < m; i++) {
    		tmp[i] = strs[0][i];
    	}
    	int res = 0;
    	for(int i = 1; i < n; i++) {
    		string &s = strs[i];
    		for(int j = 0; j < m; j++) {
    			if(not_need_delete[j]) {
    				if(tmp[j] > s[j]) {
    					not_need_delete[j] = false;
    					res ++;
    				}
    				else
    					tmp[j] = s[j];
    			}
    			if(res == m)
    				return m;
    		}
    	}
    	return res;
    }
};