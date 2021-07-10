// C++
// leetcode 59
// https://leetcode-cn.com/problems/spiral-matrix-ii/
// 

class Solution {
public:
    int x;
    int y;
    int Nminus1;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int moveFlag = 0;
    void move() {
        x += dx[moveFlag];
        y += dy[moveFlag];
        switch(moveFlag) {
            case 0: if(x + y == Nminus1)
                        ++moveFlag;
                    break;
            case 1: if(x == y)
                        ++moveFlag;
                    break;
            case 2: if(x + y == Nminus1)
                        ++moveFlag;
                    break;
            case 3: if(x == y + 1)
                        moveFlag = 0;
                    break;
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        x = 0;
        y = 0;
        moveFlag = 0;
        Nminus1 = n - 1;
        vector<vector<int>> res(n, vector<int>(n));
        int nn = n * n;
        for(int i = 1; i <= nn; ++i) {
            res[x][y]  = i;
            move();
        }
        return res;
    }
};