// C++
// leetcode 748
// https://leetcode-cn.com/problems/shortest-completing-word/

class Solution {
public:
	int getIdx(char c) {
		// 若是字母，则返回序号，a A 为 0，以此类推，z Z 为 25
		if(c >= 'a' && c <= 'z')
			return c - 'a';
		if(c >= 'A' && c <= 'Z')
			return c - 'A';
		return 26;	// 非字母返回 26
	}

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    	int res = -1, res_size = INT_MAX;	// 目标字符的 index
    	// 统计各字符数量，其中 cnt[26] 表示非字母字符的数量
    	int cnt[27] = {0};
    	for(auto c : licensePlate) cnt[getIdx(c)]++;

    	int cur[26] = {0};
    	for(int j = 0; j < words.size(); j++) {
    		// 若该词长度大于等于当前答案长度，直接不考虑
    		if(words[j].size() >= res_size) continue;
    		// 重置 cur
    		for(int i = 0; i < 26; i++)
    			cur[i] = cnt[i];
    		// 每遇上一个字母就减一
    		for(auto c : words[j]) cur[c - 'a']--;
    		// 用于传递是否合格
    		bool bad = false;
    		for(int i = 0; i < 26; i++) {
    			// 若有大于 0 的，则说明该词不能覆盖 licensePlate
    			if(cur[i] > 0) {
    				bad = true;
    				break;
    			}
    		}
    		// 不合格则进入下一个词的判断
    		if(bad) continue;
    		// 符合直接录入
			res_size = words[j].size();
			res = j;
    	}
    	return words[res];
    }
};