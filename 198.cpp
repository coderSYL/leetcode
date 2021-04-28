// c with stl(c++)
// 198
// https://leetcode-cn.com/problems/house-robber/
// 动态规划， int型数组 记录返回值

class Solution {
public:
    int max(int a, int b,bool& what){
        what = (a>b);
        if(what)
            return a;
        return b;
    }


    int rob(vector<int>& nums) {
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
};