// C++
// leetcode 812
// https://leetcode.cn/problems/largest-triangle-area/
// need refactor with convex

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0.0;
        for(int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                for(int k = j+1; k < n; ++k) {
                    int cur = abs(cross(points[k][0] - x1, points[k][1] - y1, x2-x1, y2-y1));
                    res = max(res, cur / 2.0);
                }
            }
        }
        return res;
    }

    int cross(int a, int b, int c, int d) { return a * d - b * c; }
};