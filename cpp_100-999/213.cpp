// c with stl(c++)
// 213
// https://leetcode-cn.com/problems/house-robber-ii/
// 套用 198题的解函数，改名为 rob_one

class Solution {
public:
    int max(int a, int b,bool& what){
        what = (a>b);
        if(what)
            return a;
        return b;
    }

    int rob_one(vector<int>& nums) {
        int size = nums.size();
        if( size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        int dp[size];
        bool taken;
        // 装入0与1
        dp[0] = nums[0];
        if(nums[1] >dp[0]){
            taken = true;
            dp[1] = nums[1];
        }else{
            taken = false;
            dp[1] = dp[0];
        }
        // 装入后面的
        for(int i =2; i<size; i++){
            if(taken){
                dp[i] = max(dp[i-2] +nums[i], dp[i-1], taken);
            }else{
                dp[i] = dp[i-1] +nums[i];
                taken = true;
            }
        }

        return dp[size-1];
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size== 0)
            return 0;
        if(size ==1)
            return nums[0];
        int last = nums[size-1];
        nums.pop_back();
        int a = rob_one(nums);
        nums.push_back(last);
        nums.erase(nums.begin());
        last = rob_one(nums);
        return (last>a)?last:a;
    }
};