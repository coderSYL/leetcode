// C++
// leetcode 819
// https://leetcode-cn.com/problems/most-common-word/

class Solution {
public:
	string punctuation = "!?',;. ";

	bool isPunctuationOrSpace(char c) {
		for(auto onePunct : punctuation) {
			if(c == onePunct)
				return true;
		}
		return false;
	}

	// 通过字符串得出唯一对应的一个long型数字
	long getIdx(string & s) {
		long res = 0;
		for(auto &c : s) {
			res = res * 27 + (c-'a' + 1);
		}
		return res;
	}

	// 通过一个long型数字得出唯一对应的字符串
	string getString(long idx) {
		vector<char> what;
		while(idx != 0) {
			char c = idx%27 -1 + 'a';
			what.push_back(c);
			idx /= 27;
		}
		int i = 0, j = what.size() -1;
		while(i < j) {
			swap(what[i++], what[j--]);
		}
		return string(what.begin(), what.end());
	}

    string mostCommonWord(string paragraph, vector<string>& banned) {
    	unordered_map<long, int> cnt;
    	// 把被ban的单词计数为-1000，根据题意永远都不会有一千个同样的单词
    	for(auto & s : banned)
    		cnt[getIdx(s)] = -1000;

        int n = paragraph.size();
    	for(int i = 0; i < n;  ) {
    		// 此时i必是一个好的
    		long idx = 0;
            
    		while(i < n && !isPunctuationOrSpace(paragraph[i])) {
    			int u = paragraph[i] - 'a' + 1;
    			if(u < 0)
    				u += 32;
    			idx = idx * 27 + u;
                i++;
    		}
    		cnt[idx]++;
    		while(i < n && isPunctuationOrSpace(paragraph[i])) {
    			i++;
    		}
    	}
    	
    	// 找出次数最多的单词
    	long res;
    	int max = 0;
    	for(auto &[k, v] : cnt) {
    		if(v > max) {
    			res = k;
    			max = v;
    		}
    	}
    	return getString(res);
    }
};