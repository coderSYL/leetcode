// C++
// leetcode 1436
// https://leetcode-cn.com/problems/destination-city/
// 


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int>  m;
        for(auto p : paths) {
            m[p[0]]--;
            m[p[1]]++;
        }
        for(auto it = m.begin(); it!=m.end(); it++) {
            if(it->second == 1)
                return it->first;
        }
        return  "Error, can't find an end"; // never
    }
};