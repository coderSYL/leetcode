// C++
// leetcode 49
// https://leetcode-cn.com/problems/group-anagrams/
// 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>  res;
        map<string, vector<string>> m;
        for(auto s : strs) {
            string  temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s); 
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return  res;
    }
};