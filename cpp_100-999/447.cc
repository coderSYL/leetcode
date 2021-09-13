// C++
// leetcode 447
// https://leetcode-cn.com/problems/number-of-boomerangs/
// 一开始用两个hashmap做，略慢，就看了其他人的解
// 改用一个二维数组记录距离（的平方）
// 一个数组就是一个点的数据，然后排序，计数，加进res

class Solution {
public:
    int getDis2(int a1, int a2, int b1, int b2) {
        int dx = a1 - b1;
        int dy = a2 - b2;
        return  dx * dx + dy * dy;
    }


    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        // 记录距离
        vector<vector<int>> dist(n, vector<int>(n,0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int d = getDis2(points[i][0], points[i][1], points[j][0], points[j][1]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        for(int i = 0; i < n; i++) {
            int cnt = 1;
            sort(dist[i].begin(), dist[i].end());
            for(int j = 0; j < n - 1; j++) {
                if(dist[i][j] != dist[i][j+1]) {
                    res += cnt * (cnt - 1);
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            res += cnt * (cnt - 1);
        }

        return  res;
    }
};