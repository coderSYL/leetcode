// C++
// leetcode 10
// https://leetcode-cn.com/problems/regular-expression-matching/
// dp，分情况讨论有点蛋疼

class Solution {
public:
    bool isMatch(string s, string p) {
    	bool f[s.size() + 1][p.size() + 1];
    	memset(f, 0, sizeof(f));
    	f[0][0] = true;

    	for(int i = 0; i < p.size(); i++) {
    		// 填充f[x][i + 1] 这一列
    		char c = p[i];
    		if(c == '.') {
    			// '.' 可以匹配任意字符
    			for(int j = 0; j < s.size(); j++)
    				if(f[j][i])
                        f[j + 1][i + 1] = true;
    		} else if(c == '*') {
    			// '*' 匹配任意个前面的字符
    			char cc = p[i - 1];
    			if(cc == '.') {
    				// 任意匹配，只要找到一个为true的f[x][i - 1]，
    				// 则对任意满足 y >= x 的 y,都有 f[y][i + 1] = true;
    				int j = 0;
    				while(j <= s.size() && !f[j][i - 1])
    					j++;
    				for(; j <= s.size(); j++)
    					f[j][i + 1] = true;
    				continue;
    			}
    			// 普通多个相同字符匹配
    			for(int j = 0; j <= s.size(); j++) {
    				if(!f[j][i - 1])
    					continue;
    				f[j][i + 1] = true;
	                int anotherJ = j;
		            while(anotherJ < s.size() && s[anotherJ++] == cc) {
	    				f[anotherJ][i + 1] = true;
	    			}
    			}
    		} else {
    			// 英文字母情况
    			for(int j = 0; j < s.size(); j++) {
    				if(f[j][i] && s[j] == c) {
    					f[j + 1][i + 1] = true;
    				}
    			}
    		}
    	}
    	return	f[s.size()][p.size()];
    }
};