/*
 * C++
 * leetcode 1074
 * url: https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/
 * 前缀和 + 拆分 ，然后暴力求解
 * 前缀和，用一个行列大1的表来存原表的sum，[i,j]对应的是原表从[0,0]到[i,j]的和
 * 拆分，就是用sum表的4个数字来计算一个和
 */

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int x_size = matrix.size(), y_size = matrix[0].size(), ret = 0;
        
        if(x_size * y_size * 1000 < target || x_size*y_size*1000 < -target)
            return ret;
        
        int temp[x_size+1][y_size+1];
        memset(temp, 0 , sizeof(temp));

        for(int i = 1; i<=x_size; i++){
            for(int j = 1; j<=y_size; j++){
                temp[i][j] = temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1] +matrix[i-1][j-1];
            }
        }   // 填好表了

        int x1 = 0, y1 = 0, x2 =0, y2 = 0, sum=0;

        for(x1 = 1; x1<=x_size; x1++){
            for(y1 =1; y1<=y_size; y1++){    
                for(x2 = x1; x2<=x_size; x2++){
                    for(y2 = y1; y2<=y_size; y2++){  // 固定四个角
                        sum = temp[x2][y2] - temp[x2][y1-1] -temp[x1-1][y2] +temp[x1-1][y1-1];
                        if(sum == target)
                            ret++;
                    }
                }
            }
        }
        return ret;
    }
};