// C++
// leetcode 1704
// https://leetcode.cn/problems/determine-if-string-halves-are-alike/

class Solution {
public:
	// 若 c 是大写或小写的元音字符，返回 0
	// 否则返回 1
    int getIdx(char c) {
        switch (c) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return 0;
            default:
                break;
        }
        return 1;
    }


    bool halvesAreAlike(string s) {
        int cnt[2];
        memset(cnt, 0, sizeof(cnt));
        int half = s.size() / 2;
        for(int i = 0; i < s.size(); i++) {
            cnt[getIdx(s[i])] += (i < half ? 1 : -1);
        }
        if (cnt[0] != 0)
            return false;
        return true;
    }
};