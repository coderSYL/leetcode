// C++
// leetcode 
// https://leetcode-cn.com/contest/weekly-contest-249/problems/unique-length-3-palindromic-subsequences/
// 周赛2

class Solution {
public:
    int countPalindromicSubsequence(string s) {
    	// 最多26 * 26 种，打算用dp
    	// 用一个map<char, set<char>> 记录一个字母是否出现过，以及它后面有谁
    	// 如果是第一次出现，则在map里注册一下，如果不是，就结算一次
    	// a ASCII 97
    	int res[26] = {0};
    	map<char, set<char> > m;
    	int n = s.size();
    	for(auto c : s) {
    		for(auto it = m.begin(); it != m.end(); ++it) {
    			// 先给已经有了的
    		}
    		if(m.find(c) == m.end()) {
    			// 不存在的情况
    			for(auto it = m.begin(); it != m.end(); ++it) {
    				it->second.insert(c);
    			}
    			m[c] = set<char>{};
    		} else {
    			// 存在的情况
    			res[(int)(c - 97)] = m[c].size();	// 结算单个字母
    			for(auto it = m.begin(); it != m.end(); ++it) {
    				it->second.insert(c);
    			}
    		}
    	}
    	int total = 0;
    	for(int i = 0; i < 26; ++i) {
    		total += res[i];
    	}
    	return total;
    }
};