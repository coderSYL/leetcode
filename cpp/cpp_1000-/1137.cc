// C++
// leetcode 1137
// https://leetcode-cn.com/problems/n-th-tribonacci-number/
// 方法1:经典dp
// 方法2:矩阵快速幂，本题中不划算，因为原本计算并不多


class Solution {
public:
    int tribonacci(int n) {
        int m = max(n + 1, 3);
        int dp[m];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};


// // 方法二
// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n < 2)
//             return  n;
//         int mat[3][3] = { {1,1,1} , {1,0,0} , {0,1,0} };
//         int tmp[3][3] = { {1,1,1} , {1,0,0} , {0,1,0} };
//         int final[3][3] = { {1,0,0} , {0,1,0} , {0,0,1} };
//         int k = n - 2;
//         bool firstTurn = true;
//         while(k > 0) {
//             if(firstTurn) {
//                 firstTurn = false;
//             } else {
//                 mat_3_self(mat, tmp);
//             }
//             if(k % 2 == 1) {
//                 mat_3(final, mat, tmp);
//             }
//             k /= 2;
//         }
//         return final[0][0] + final[0][1];
//     }


//     void mat_3_self(int a[][3], int b[][3]) {
//         // 计算a的乘积，存到a里，b用来辅助
//         for(int i = 0; i < 3; i++) {
//             for(int j = 0; j < 3; j++) {
//                 // 第i横行 乘以 第j竖列
//                 b[i][j] = a[i][0] * a[0][j] + a[i][1] * a[1][j] + a[i][2] * a[2][j]; 
//             }
//         }


//         for(int i = 0; i < 3; i++) {
//             for(int j = 0; j < 3; j++) {
//                 a[i][j] = b[i][j];
//             }
//         }
//         return;
//     }

//     void mat_3(int final[][3], int m[][3], int tmp[][3]) {
//         // 计算final 与 m 的乘积，最后存在final里，tmp是临时用的，m不动
//         for(int i = 0; i < 3; i++) {
//             for(int j = 0; j < 3; j++) {
//                 // 第i横行 乘以 第j竖列
//                 tmp[i][j] = final[i][0] * m[0][j] + final[i][1] * m[1][j] + final[i][2] * m[2][j]; 
//             }
//         }

//         for(int i = 0; i < 3; i++) {
//             for(int j = 0; j < 3; j++) {
//                 final[i][j] = tmp[i][j];
//             }
//         }
//         return;
//     }
// };