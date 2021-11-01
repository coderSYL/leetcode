// C++
// leetcode 1
// https://leetcode-cn.com/problems/two-sum/
// 检查最特殊的情况，两个n0 = n1，且n0 + n1 = target，若非此情况，则：
// 用hash录入nums中的值与index
// 对nums进行排序
// 用双指针法找到符合的两个数a，b
// 用hash找到a，b的角标


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        if(target % 2 == 0) {
            int tt = target / 2;
            for(int i = 0; i < n; i++) {
                if(nums[i] == tt)
                    res.push_back(i);
            }
            if(res.size() == 2)
                return  res;
            else
                res.clear();
        }

        unordered_map<int, int> m; // < val, index >
        for(int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        while(true) {
            if(nums[i] +nums[j] > target){
                j--;
            }else if(nums[i] +nums[j] < target){
                i++;
            }else{
                res.push_back(m[nums[i]]);
                res.push_back(m[nums[j]]);
                break;
            }
        }
        return  res;
    }
};