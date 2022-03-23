// C++
// leetcode 594
// https://leetcode-cn.com/problems/longest-harmonious-subsequence/

class Solution {
private:
    unordered_map<int, int> map;
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        for (auto& num : nums)
            map[num]++;
        for(auto [k,v] : map)
            if(map.find(k + 1) != map.end())
                res = max(res, v + map[k + 1]);
        return res;
    }
};