// C++
// leetcode 1592
// https://leetcode.cn/problems/rearrange-spaces-between-words/

class Solution {
public:
    string reorderSpaces(string text) {
    	int n = text.size(), spaceCnt = 0, wordCnt = 0;
    	vector<char> tmp(n, ' ');
    	for (int i = 0; i < n; ) {
    		int j = i;
    		while (j < n && text[j] == ' ')
    			j++;
    		spaceCnt += j - i;
    		if (j < n)
    			wordCnt++;
    		while(j < n && text[j] != ' ')
    			j++;
    		
    		i = j;
    	}
        // cout<<spaceCnt<<" : "<<wordCnt<<endl;
    	int step = (wordCnt == 1 ? 0 : spaceCnt / (wordCnt - 1));
    	int p1 = 0, p2 = 0;
    	while(wordCnt--) {
    		// p1 is for tmp
    		// p2 is for text
    		while(text[p2] == ' ')
    			p2++;
    		while (p2 < n && text[p2] != ' ')
    			tmp[p1++] = text[p2++];
    		p1 += step;
    	}
    	return string(tmp.begin(), tmp.end());
    }
};