// C++
// leetcode 1743
// https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/
// 

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int , int> cnts;
        unordered_map<int , vector<int>> ok;
        for(auto x : adjacentPairs) {
            int a = x[0], b = x[1];
            ++cnts[a];
            ++cnts[b];
            ok[a].push_back( b );
            ok[b].push_back( a );
        }
        // cout<<"map done"<<endl;
        vector<int> res(n);

        int first;
        for(auto it = cnts.begin(); it != cnts.end(); ++it) {
            if(it -> second == 1) {
                first = it -> first;
                break;
            }
        }
        res[0] = first;
        res[1] = ok[first][0];
        for(int i = 2; i < n; ++i) {
            int x = res[i - 1];
            for(auto j : ok[x]) {
                if(j != res[i - 2]) {
                    res[i] = j;
                    break;
                }
            }
        }
        return  res;
    }
};