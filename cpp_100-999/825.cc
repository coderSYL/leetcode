// C++
// leetcode 825
// https://leetcode-cn.com/problems/friends-of-appropriate-ages/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int num[121];
        memset(num, 0, sizeof(num));
        int res = 0;
        for(auto & x : ages) {
            if(x < 15) continue;
            ++num[x];
        }

        for(int i = 15; i <= 120; i++) {
            if(num[i] == 0) continue;
            int tmp = 0;
            for(int j = i / 2 + 8; j <= i; ++j)
                tmp += num[j];
            res += num[i] * (tmp - 1);
        }
        return res;
    }
};