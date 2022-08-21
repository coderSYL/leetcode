// C++
// leetcode 1455
// https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// 从句子里切分出单词，并对每个单词check

class Solution {
public:
    int isPrefixOfWord(string sentence, string word) {
    	int idx = 0, n = sentence.size(), m = word.size();

    	// check one word per loop 
    	for (int i = 0; i < n; i++) {
    		idx++;

    		// check
    		int p = 0;
    		while (i + p < n && p < m) {
    			if (sentence[i + p] == word[p])
    				p++;
    			else break;
    		}
    		if (p == m)
    			return idx;

    		// find position for next word
    		i += p;
    		while(i < n && sentence[i] != ' ') {
    			i++;
    		}
    	}

    	return -1;
    }
};