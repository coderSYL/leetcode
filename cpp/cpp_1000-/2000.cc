// C++
// leetcode 2000
// https://leetcode-cn.com/problems/reverse-prefix-of-word/

class Solution {
public:
    string reversePrefix(string word, char ch) {
    	int idx = 0;
    	int n = word.size();
    	while(idx < n && word[idx] != ch) idx++;
    	if(idx == n) return word;
    	vector<char> res(n);
    	for(int i = 0; i <= idx; i++)
    		res[i] = word[idx - i];
    	for(int i = idx + 1; i < n; i++)
    		res[i] = word[i];
    	return string(res.begin(), res.end());
    }
};