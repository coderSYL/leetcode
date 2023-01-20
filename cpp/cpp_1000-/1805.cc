// C++
// leetcode 1805
// https://leetcode.cn/problems/number-of-different-integers-in-a-string/

class Solution {
public:
	const static int N = 1010;
	int trie[N][10];
	int count[N];
	int idx = 0;

	void insert(string s) {
		int p = 0;
		int i = 0;
		while(i < s.size() && s[i] == '0')
			i++;
		for(; i < s.size(); i++) {
			int u = s[i] - '0';
			if(trie[p][u] == 0)
				trie[p][u] = ++idx;
			p = trie[p][u];
		}
		count[p]++;
	}

	int cnt(int u) {
		int res = 0;
		if (count[u] != 0)
			res++;
		for (int i = 0; i < 10; i++) {
			if (trie[u][i] != 0) {
				res += cnt(trie[u][i]);
			}
		}
		return res;
	}

	bool isDigit(char c) {
		if ( c >= '0' && c <= '9')
			return true;
		return false;
	}

    int numDifferentIntegers(string word) {
    	memset(count, 0, sizeof(count));
    	for (int i = 0; i < word.size(); ) {
    		while(i < word.size() && !isDigit(word[i]))
    			i++;
    		int j = i;
    		while (j < word.size() && isDigit(word[j]) )
    			j++;
    		if (i == j)
    			break;
    		insert(word.substr(i, j - i));
            i = j;
    	}
    	return cnt(0);
    }
};