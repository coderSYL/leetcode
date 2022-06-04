// C++
// leetcode 478
// https://leetcode.cn/problems/generate-random-point-in-a-circle/

class Solution {
public:
    double get() {
        return double(rand()) / RAND_MAX * 2 - 1;
    }

    double x, y, r;
    double PI = acos(-1);
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double a = get(), b = get();
        while(a * a + b * b > 1.0) {
            a = get();
            b = get();
        }
        return vector<double>{x + r * a, y + r * b};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */