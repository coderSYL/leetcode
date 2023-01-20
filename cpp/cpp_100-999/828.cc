// C++
// leetcode 828
// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

class Solution {
public:
    int uniqueLetterString(string s) {
        // l[i] 代表以 s[i]为左端点且只含一个 s[i] 的最长字符串长度
        // r[i] 代表以 s[i]为右端点且只含一个 s[i] 的最长字符串长度
        int n = s.size(), l[n], r[n];
        memset(r, -1, sizeof(r));

        for (int i = 0; i < n; i++) {
            // 找 l[i]
            int x = i + 1;
            char c = s[i];
            while(x < n && s[x] != c)
                x++;
            l[i] = x - i;

            // 如果 x 不是 n，可以填入 r[x]
            if (x != n)
                r[x] = l[i];

            // 如果之前 r[i] 没被作为别人的 r[x]填入
            // 说明 左侧没有任何 s[i] 字符
            if (r[i] == -1)
                r[i] = i + 1;
            // cout<<l[i]<<" : "<<r[i]<<endl;
        }

        // 统计答案
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += l[i] * r[i];
        }

        return res;
    }
};