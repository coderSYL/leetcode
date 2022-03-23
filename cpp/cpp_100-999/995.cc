// C++
// leetcode 995
// https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/
// 遍历，如果为 0 则对从此开始的 k 位进行翻转
// 直接翻转会超时，所以用一个 数组来判断位置 i 是否翻转了

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> arr(n + 1, 0);
        for(int i = 0, cnt = 0; i < n; ++i) {
            cnt +=  arr[i];
            if((cnt + nums[i]) % 2 == 0) {
                if(i + k > n)
                    return  -1;
                ++res;
                ++arr[i + 1];
                --arr[i + k];
            }
        }
        return res;
    }
};