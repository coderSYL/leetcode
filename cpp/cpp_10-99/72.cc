// C++
// leetcode 72
// https://leetcode-cn.com/problems/edit-distance/
// dp，第一次见这种的

class Solution {
public:
    int m3(int a, int b, int c) {
        // 返回abc三个值中的最小值
        if(a > b)   a = b;
        if(a > c)   a = c;
        return  a;
    }


    int minDistance(string w1, string w2) {
        int n1 = w1.size();
        int n2 = w2.size();
        vector<vector<int>> d(n1 + 1, vector<int>(n2+1));

        // 初始化
        for(int i = 0; i <= n1; i++) {
            d[i][0] = i;
        }
        for(int i = 0; i <= n2; i++) {
            d[0][i] = i;
        }

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                int gai = d[i-1][j-1];
                if(w1[i-1] != w2[j-1])  gai++;
                d[i][j] = m3(d[i-1][j]+1, d[i][j-1]+1, gai);
            }
        }

        return  d[n1][n2];
    }
};