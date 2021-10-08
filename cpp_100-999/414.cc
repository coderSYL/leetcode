// C++
// leetcode 414
// https://leetcode-cn.com/problems/third-maximum-number/
// 


class Solution {
public:
    long MIN = (long)-1e18;
    int thirdMax(vector<int>& nums) {
        long a = MIN, b = MIN, c = MIN;
    	for(auto x : nums) {
            if(x == a || x == b || x == c)
                continue;
            if(x > a) {
                c = b;
                b = a;
                a = x;
            } else if(x > b) {
                c = b;
                b = x;
            } else if(x > c) {
                c = x;
            }
        }
        return  (c == MIN ? (int)a : (int)c);
    }
};