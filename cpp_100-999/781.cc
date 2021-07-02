// C++
// leetcode 781
// https://leetcode-cn.com/problems/rabbits-in-forest/
// 先统计回答，然后根据统计的回答与相应的频率算最少的兔子数

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        for(auto x : answers) {
            if(m.count(x) == 0)
                m[x] = 1;
            else
                ++m[x];
        }
        int res = 0;
        for(auto it = m.begin(); it != m.end(); ++it) {
            int x = it -> first + 1;
            int times = it -> second;
            if(times % x != 0)
                times = times - (times % x) + x;
            res += times;
        }
        return res;
    }
};