// C++
// leetcode 438
// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
// 使用两个计数器，一个预处理字符串p，另一个用来遍历字符串s

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int>	res;
    	int cntP[26];
    	int cur[26];
    	memset(cntP, 0, sizeof(cntP));
    	memset(cur, 0, sizeof(cur));
    	// 预处理字符串p
    	for(auto c : p)
    		cntP[c - 'a']++;
    	// i j 为指针
    	int i = 0, j = 0, now = 0;
    	while(j < s.size()) {
    		char c = s[j++];
    		int u = c - 'a';
    		if(cur[u] < cntP[u]) {
    			cur[u]++;
    			// 大小一致则可以录入
    			if(j - i == p.size())
    				res.push_back(i);
    		} else {
    			// 字符 c 的数量超了，需要移动 i 指针
    			while(s[i] != c) {
    				cur[s[i++] - 'a']--;
    				now--;
    			}
    			i++;
    			// 大小一致则录入答案
    			if(j - i == p.size())
    				res.push_back(i);
    		}
    	}
    	return	res;
    }
};