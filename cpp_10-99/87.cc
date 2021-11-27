// C++
// leetcode 87
// https://leetcode-cn.com/problems/scramble-string/
// dp，还算有点难度，本来想

class Solution {
public:
    bool isScramble(string s1, string s2) {
    	int n = s1.size();
    	// f[i][j][k] 代表s1[i]与s2[j]开头的长度为 k 的字符串是否符合条件
    	vector<vector<vector<bool>>>	f(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
    	// 先填充长度为 1 的情况
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++)
    			f[i][j][1] =  (s1[i] == s2[j]);
    	// 其他长度的情况
    	for(int length = 2; length <= n; length++) {
    		// i 与 j 的范围都是 [0, n - length]
    		int end = n - length + 1;
    		for(int i = 0; i < end; i++) {
    			for(int j = 0; j < end; j++) {
    				// 需要确定 f[i][j][length]
    				for(int len1 = 1; len1 < length; len1++) {
    					// xy xy
    					if(f[i][j][len1] && f[i + len1][j + len1][length - len1]) {
    						f[i][j][length] = true;
    						break;
    					}
    					// xy yx
    					if(f[i][j + length - len1][len1] && f[i + len1][j][length - len1]) {
    						f[i][j][length] = true;
    						break;
    					}
    				}
    			}
    		}
    	}
    	return	f[0][0][n];
    }
};