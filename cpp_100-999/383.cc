// C++
// leetcode 383
// https://leetcode-cn.com/problems/ransom-note/
// 简单模拟，仅限于输入“字符串只包含小写字母”的情况

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	// 统计magazine
    	int cnt[26] = {0};
    	for(auto c : magazine)
    		cnt[c - 'a']++;
    	// 统计ransomNote
    	for(auto c : ransomNote)
    		cnt[c - 'a']--;
    	for(int i = 0; i < 26; ++i)
    		if(cnt[i] < 0)
    			return false;
    	return true;
    }
};