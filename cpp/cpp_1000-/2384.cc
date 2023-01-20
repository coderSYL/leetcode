// C++
// leetcode 2384
// https://leetcode.cn/problems/largest-palindromic-number/

class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < num.size(); i++)
        	cnt[num[i] - '0']++;

        vector<char> tmp;
        for (int i = 9; i >= 0; i--) {
        	if (i == 0 && tmp.size() == 0)
        		continue;
            tmp.insert(tmp.end(), cnt[i] >> 1, (char) ('0' + i));
        	cnt[i] &= 1;
        }

        int p = tmp.size() - 1;
        for (int i = 9; i >= 0; i--) {
        	if (cnt[i] != 0) {
        		tmp.push_back((char) ('0' + i));
        		break;
        	}
        }

        while (p >= 0) {
        	tmp.push_back(tmp[p--]);
        }

        return string(tmp.begin(), tmp.end());
    }
};