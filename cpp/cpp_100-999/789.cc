// C++
// leetcode 789
// https://leetcode-cn.com/problems/escape-the-ghosts/
// 曼哈顿距离？

class Solution {
public:
    int ab(int a) {
        if(a < 0)   return  -a;
        return  a;
    }

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int xx = target[0], yy = target[1]
        int me = ab( xx ) + ab( yy );
        for(auto co : ghosts) {
            int loop = ab(xx - co[0]) + ab(yy - co[1]);
            if(loop <= me)
                return  false;
        }
        return  true;
    }
};