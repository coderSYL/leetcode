// C++
// leetcode 1833
// https://leetcode-cn.com/problems/maximum-ice-cream-bars/
// 先排序，然后简单的循环判断

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int SIZE = costs.size();
        int res = 0;
        while(res < SIZE) {
            if(coins < costs[res])
                return  res;
            coins -= costs[res];
            ++res;
        }
        return res;
    }
};