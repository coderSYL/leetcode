// C++
// leetcode 63
// https://leetcode-cn.com/problems/unique-paths-ii/
// dp，可以利用原有的格子，不用新加格子


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1)
            return  0;
        obstacleGrid[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i + j == 0)
                    continue;
                int num = obstacleGrid[i][j];
                obstacleGrid[i][j] = 0;
                if(num == 1)
                    continue;
                if(i > 0)
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                if(j > 0)
                    obstacleGrid[i][j] += obstacleGrid[i][j-1];
            }
        }
        return  obstacleGrid[m-1][n-1];
    }
};