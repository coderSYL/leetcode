// C++
// leetcode interview 17.11
// https://leetcode.cn/problems/find-closest-lcci/

class Solution {
public:
    int findClosest(vector<string>& words, string w1, string w2) {
    	int n = words.size(), p1 = -n, p2 = -n, res = n;
    	for(int i = 0; i < n; ++i) {
    		if(words[i] == w1) {
    			res =min(res, i-p2);
    			p1 = i;
    		} else if(words[i] == w2) {
    			res =min(res, i-p1);
    			p2 = i;
    		}
    	}
    	return res;
    }
};