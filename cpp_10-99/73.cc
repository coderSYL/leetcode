// C++
// leetcode 73
// https://leetcode-cn.com/problems/set-matrix-zeroes/
// 先用两个bool标记第0行和第0列是否需要置0
// 然后用第0行与第0列来标记其它行是否需要置0
// 然后置其它行列的0
// 最后置第0行列的0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool lineZero = false;
        bool rowZero = false;
        int m = matrix.size();
        int n = matrix[0].size();


        for(int x : matrix[0]) {
            if(x == 0) {
                lineZero = true;
                break;
            }
        }   // lineZero check
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0) {
                rowZero = true;
                break;
            }
        }   // rowZero check


        for(int i = 1; i < m; ++i) {
            for(int x : matrix[i]) {
                if(x == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }   // other lines check

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[j][i] == 0) {
                    matrix[0][i] = 0;
                    break;
                }
            }
        }   // other rows check

        // 开始置 0 
        for(int i = 1; i < m ;++i) {
            if(matrix[i][0] == 0) {
                for(auto& x : matrix[i])
                    x = 0;
            }
        }

        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < m; ++j)
                    matrix[j][i] = 0;
            }
        }

        if(lineZero) {
            for(auto& x : matrix[0])
                x = 0;
        }

        if(rowZero) {
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
        return;
    }
};