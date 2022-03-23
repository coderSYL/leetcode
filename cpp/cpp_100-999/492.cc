// C++
// leetcode 492
// https://leetcode-cn.com/problems/construct-the-rectangle/
// 


class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = 1, r = area;
        int L = 1, W = area;

        while(l < r) {
            r = area / l;
            if(area % l == 0) {
                L = r;
                W = l;
            }
            l++;
        }
        
        return  vector<int>{L,W};
    }
};