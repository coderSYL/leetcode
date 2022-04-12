// C++
// leetcode 796
// https://leetcode-cn.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
    	// 先做一个字符种类与数量的统计，如果不一样，那么铁定
    	int cnt1[26], cnt2[26];
    	memset(cnt1, 0, sizeof(cnt1));
    	memset(cnt2, 0, sizeof(cnt2));
    	int n = s.size(), m = goal.size();
    	if(m != n)
    		return false;
    	vector<int> goodStart;
    	char sFirst = s[0];
    	for(auto &c : s)
    		cnt1[c-'a']++;
    	for(int i = 0; i < n; i++) {
    		if(goal[i] == sFirst)
    			goodStart.push_back(i);
    		cnt2[goal[i] - 'a']++;
    	}
    	for(int i = 0; i < 26; i++)
    		if(cnt1[i] != cnt2[i])
    			return false;

    	
    	for(auto goalStart : goodStart) {
    		bool ok = true;
    		int j = goalStart;
    		for(int i = 0; i < n; i++) {
    			if(s[i] != goal[j]) {
    				ok = false;
    				break;
    			}
    			j = (j + 1) % n;
    		}
    		if(ok)
    			return true;
    	}
    	return false;
    }
};