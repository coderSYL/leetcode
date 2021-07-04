// C++
// 周赛 2021-07-04
// 4

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        int shortFriend = 0;
        int hisCities = paths[0].size();

        for(int i = 1; i < m; ++i) {
            if(paths[i].size() < hisCities) {
                shortFriend = i;
                hisCities = paths[i].size();
            }
        }
        // common 代表 公共路径，如果没有则删除
        vector<int> &common = paths[shortFriend];
        int resPossible[ hisCities];
        set<int> left;
        for(int i = 0; i < hisCities; ++i) {
            resPossible[i] = hisCities - i;
            left.insert(i);
        }

        for(int i = 0; i < m; ++i) {
            // 相当于对resPossible 进行一个check
            if(left.empty())
                break;
            int temp[hisCities] = {0};
            int toBedealed = -1;
            for(int i = 0; i < hisCities; i++) {
                if(left.find(i) == left.end()) {
                    --toBedealed;
                    continue;
                }
                if(toBedealed >= 0) {
                    temp[i] = toBedealed;
                    --toBedealed;
                    continue;
                }
                // 真正的找
                vector<int> &loop = paths[i];
                int nn = paths[i].size();
                // 遍历一遍路径，寻找
                for(int j = 0; j < nn; ++j) {
                    if(paths[j] != common[i])
                        continue;

                }
            }
        }   // one loop, one    
    }
};