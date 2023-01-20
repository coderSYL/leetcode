// C++
// leetcode 1758
// https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
        	if (s[i] - '0' == i % 2)
        		cnt++;
        }
        return min(cnt, n - cnt);
    }
};