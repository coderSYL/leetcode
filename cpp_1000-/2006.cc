// C++
// leetcode 2006
// https://leetcode-cn.com/problems/count-number-of-pairs-with-absolute-difference-k/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> cnt;
        int res = 0;
        for(int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        
        auto it_i = cnt.begin(), it_j = it_i;
        it_j++;
        while(it_i != cnt.end()) {
            while(it_j != cnt.end() && it_j->first - it_i->first < k) it_j++;
            if(it_j != cnt.end() && it_j->first - it_i->first == k) {
                res += it_i->second * it_j->second;
            }
            it_i++;
        }
        return res;
    }
};