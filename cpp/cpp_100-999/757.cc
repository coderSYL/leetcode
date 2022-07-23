// C++
// leetcode 757
// https://leetcode.cn/problems/set-intersection-size-at-least-two/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[1] == b[1]) {
            return b[0] - a[0] <= 0;
        }

        return a[1] - b[1] <= 0;
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int a = -1, b = -1, res = 0;
        for (auto &i : intervals) {
            if (i[0] > b) {
                a = i[1] - 1;
                b = i[1];
                res += 2;
            } else if (i[0] > a) {
                a = b;
                b = i[1];
                res++;
            }
        }

        return res;
    }
};