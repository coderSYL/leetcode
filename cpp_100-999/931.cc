// C++
// leetcode 931
// https://leetcode-cn.com/problems/minimum-falling-path-sum/
// 


class Solution {
public:
    int min3(int a, int b, int c) {
        if(b < a)
            a = b;
        if(c < a)
            a = c;
        return  a;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int a = j - 1;
                int b = j;
                int c = j + 1;
                if(a < 0)
                    a++;
                if(c == n)
                    c--;
                matrix[i][j] += min3(matrix[i-1][a], matrix[i-1][b], matrix[i-1][c]);
            }
        }
        
        int res = INT_MAX;
        for(auto x : matrix[n - 1])
            res = min(res, x);
        return  res;
    }
};