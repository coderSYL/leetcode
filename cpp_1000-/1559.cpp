// c with stl(c++)
// 1559
// https://leetcode-cn.com/problems/detect-cycles-in-2d-grid/
// 好操蛋的题，我太弱了


class Solution {
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    bool visited[500][500];
    bool flag = false;
    int M,N;
public:
    bool containsCycle(vector<vector<char>>& grid){
        M = grid.size();
        N = grid[0].size();
        memset(visited,0,sizeof(visited));
        for(int i = 0; i<M ; i++){
            for(int j = 0; j<N; j++)
                if(!visited[i][j]){
                    dfs(grid,i,j,-1,-1);
                    if(flag)
                        return true;
                }
        }
        return flag;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int prei, int prej){
        if(visited[i][j]){
            flag = true;
            return;
        }
        visited[i][j] = true;
        for(int count = 0; count <4; count++){
            int x = i+dx[count], y = j +dy[count];
            if(x>=0 && x<M && y>=0 && y<N &&(x != prei || y!= prej)&& grid[x][y] == grid[i][j])
                dfs(grid, x,y,i,j);
        }
    }
};