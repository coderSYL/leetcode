// C++
// leetcode 165
// https://leetcode-cn.com/problems/compare-version-numbers/
// 

class Solution {
public:
    vector<int> v1;
    vector<int> v2;

    void set(vector<int>& v, string s) {
        int n = s.size();
        int p = 0;
        int cur = 0;
        while(p < n)  {
            if(s[p] == '.') {
                v.push_back(cur);
                cur = 0;
                p++;
                continue;
            }
            int x = (int)s[p] - 48;
            if(!(cur == 0 && x == 0))
                cur = cur * 10 + x;
            p++;
        }
        if(cur != 0)
            v.push_back(cur);
    }

    int compareVersion(string version1, string version2) {
        set(v1, version1);
        set(v2, version2);
        int n1 = v1.size();
        int n2 = v2.size();
        if(n1 < n2) {
            v1.resize(n2, 0);
            n1 = n2;
        }
        if(n1 > n2) {
            v2.resize(n1, 0);
            n2 = n1;
        }
        int i = 0;
        while(i < n1) {
            if(v1[i] <  v2[i]) {
                return -1;
            }
            if(v1[i] >  v2[i]) {
                return 1;
            }
            i++;
        }
        return  0;
    }
};