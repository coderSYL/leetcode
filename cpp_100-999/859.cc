// C++
// leetcode 859
// https://leetcode-cn.com/problems/buddy-strings/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
    	// 长度不同，则肯定不匹配
        if(s.size() != goal.size())	return false;
        // 不同的位置的index
    	int a = -1, b = -1;
    	for(int i = 0; i < s.size(); i++)
    		if(s[i] != goal[i]) {
    			if(a < 0)	a = i;
    			else if(b < 0)	b = i;
    			else	return	false;
    		}
    	// 刚好只有两个位置不同且能互换
    	if((a >= 0 && b >= 0) && (s[a] == goal[b] && s[b] == goal[a]))
    		return	true;
    	// 若全部都一样，则需要有重复字符同样能换
        if(a < 0) {
        	set<char>	set;
        	for(auto c : s) {
        		if(set.find(c) != set.end()) {
        			return	true;
        		} else {
        			set.insert(c);
        		}
        	}
        }
    	return false;
    }
};