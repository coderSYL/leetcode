// C++
// leetcode 1813
// https://leetcode.cn/problems/sentence-similarity-iii/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
    	// 确保 sentence1 更短
    	if (sentence1.size() > sentence2.size())
    		sentence1.swap(sentence2);
    	int n1 = sentence1.size(), n2 = sentence2.size(), p = 0;
    	while (p < n1 && sentence1[p] == sentence2[p])
    		p++;

        if (p == n2)
            return true;
        if (p == n1 && sentence2[p] == ' ')
        	return true;
        if (sentence1[p] == ' ' && sentence2[p] != ' ')
        	p--;
        while (p >= 0 && sentence1[p] != ' ')
    		p--;
    	if (p == n1)
    		return true;
        

    	int q = p + n2 - n1;
    	if (q != -1 && sentence2[q] != ' ')
    		return false;
    	for (int i = p + 1, j = q + 1; i < n1; i++, j++) {
    		if (sentence1[i] != sentence2[j])
    			return false;
    	}
    	return true;
    }
};