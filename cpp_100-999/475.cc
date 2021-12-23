// C++
// leetcode 475
// https://leetcode-cn.com/problems/heaters/

class Solution {
public:
    // 返回 a - b 的绝对值 |a-b|
    inline int abso(int a, int b) {
        return (a > b ? a - b : b - a);
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        int n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for(auto& pos : houses) {
            int minDis = INT_MAX;
            int l = 0, r = n - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if (heaters[mid] < pos) {
                    l = mid + 1;
                } else if (heaters[mid] > pos) {
                    r = mid - 1;
                } else {
                    r = mid;
                    break;
                }
            }
            if(r >= 0)  minDis = min(minDis, abso(pos, heaters[r]));
            if(r > 0)   minDis = min(minDis, abso(pos, heaters[r - 1]));
            if(r < n - 1)   minDis = min(minDis, abso(pos, heaters[r + 1]));
            res = max(res, minDis);
        }
        return res;
    }
};