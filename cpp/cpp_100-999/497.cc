// C++
// leetcode 497
// https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/
// 把长方形的坐标数据保存下来
// 用一维数组把长方形的面积作为权重算出前缀和
// 每次先找到坐标所在长方形，在找坐标

class Solution {
public:
    vector<vector<int>>& rs;
    vector<int> sum;
    int n;
    Solution(vector<vector<int>>& rects) {
        n = rects.size();
        rs.swap(rects);
        sum.resize(n+1);
        for(int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + (rs[i - 1][2] - rs[i - 1][0] + 1) * (rs[i - 1][3] - rs[i - 1][1] + 1);
        }
    }
    
    vector<int> pick() {
        int val = rand()%sum[n] + 1;
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(sum[mid] >= val)
                r = mid;
            else
                l = mid + 1;
        }
        vector<int> &cur = rs[r-1];
        int x = rand() % (cur[2] - cur[0] + 1) + cur[0];
        int y = rand() % (cur[3] - cur[1] + 1) + cur[1];
        return vector<int>{x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */