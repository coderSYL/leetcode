// C++
// leetcode 467
// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size(), res = 0, base = 0;
        priority_queue<int> pq;
        // f[i][c] = true 
        // means it exists substring whose size equals i+base
        // and start with (char)('a' + c)
        bool f[26][26];
        memset(f, 0, sizeof(f));
        // processing p
        for(int i = 0, j = 0; i < n; ) {
            char next = p[i];
            while(j < n && p[j] == next) {
                j++;
                if(next != 'z')
                    next = next + 1;
                else
                    next = 'a';
            }
            // cur contains the information of
            // 1. length
            // 2. start char
            int cur = (j-i) * 26 + p[i] - 'a';
            if(cur >= base)
                pq.push(cur);
            base = max(base, cur/26 - 26);
            i = j;
        }

        // process the longest substring
        int x = pq.top() / 26, y = pq.top() % 26;
        pq.pop();
        base = max(x-25, 0);
        for(int i = x; i-base > 0; --i) {
            int set_num = x - i + 1;
            int start = y;
            while(set_num--) {
                f[i-base][start] = true;
                start = (start+1) % 26;
            }
        }
        // process the rest
        while(!pq.empty()) {
            x = pq.top() / 26;
            if(x <= base)
                break;
            y = pq.top() % 26;
            pq.pop();
            for(int i = x; i > base; --i) {
                int set_num = x - i + 1;
                int start = y;
                while(set_num--) {
                    f[i-base][start] = true;
                    start = (start+1) % 26;
                }
            }
        }
        // calculate part of res according f[i][j]
        for(int i = 1; i <= 25; ++i) {
            for(int j = 0; j <= 25; ++j)
                if(f[i][j]) {
                    res++;
                }
        }
        // for length l <= base, all 26 chars count
        res += 26 * base;
        return res;
    }
};