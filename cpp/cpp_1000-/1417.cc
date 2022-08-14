// C++
// leetcode 1417
// https://leetcode.cn/problems/reformat-the-string/

class Solution {
public:
	bool isNum(char c) {
		if (c >= '0' && c <= '9')
			return true;

		return false;
	}

    string reformat(string s) {
    	int n = s.size();

    	// 统计字母与数字的个数
    	int letterCnt = 0, numCnt = 0;
    	for (auto c : s) {
    		if (isNum(c))
                numCnt++;
    		else
    			letterCnt++;
    	}

    	// 判断是否有解
    	if (letterCnt + 1 < numCnt || numCnt + 1 < letterCnt)
    		return "";

    	// 拼接出新字符串
    	bool numTurn = (numCnt >= letterCnt);
    	vector<char> tmp(n);
    	int letter_p = 0, num_p = 0;
    	for(int i = 0; i < n; i++) {
    		if (numTurn) {
    			while (!isNum(s[num_p])) {
    				num_p++;
    			}
    			tmp[i] = s[num_p++];
    		} else {
    			while (isNum(s[letter_p])) {
    				letter_p++;
    			}
    			tmp[i] = s[letter_p++];
    		}
    		numTurn = !numTurn;
    	}

    	return string(tmp.begin(), tmp.end());
    }
};