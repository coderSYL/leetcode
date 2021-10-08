// C++
// leetcode 279
// https://leetcode-cn.com/problems/perfect-squares/
// 

class Solution {
public:
    // 返回数的平方为不超过be的最大的平方数
    int low_Sqrt(int be){
        int ret =1;
        while(ret*ret <= be)
            ret++;
        ret--;
        return ret;
    }

    // // 上面函数的二分写法，用在leetcode上跟上面的写法差不过快，可能是数据量不够多不够大的原因
    // int low_Sqrt(int be){
    //     int l = 1, r = be;
    //     while(l < r) {
    //         int mid = (l + r) / 2;
    //         if(mid * mid < be)
    //             l = mid + 1;    // l可能爆了
    //         else if(mid * mid > be)
    //             r = mid - 1;    // r必定小与等于 good
    //         else
    //             return  mid;
    //     }
    //     return r;
    // }

    int numSquares(int n) {
        // create dp and initialize it
        // 用leetcode上测试用例来看数组比vector要快，且使用空间也更小
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        // determinate the last num
        int END = low_Sqrt(n);
        // do the dp
        for(int i = 1; i <= END; i++){
            int square_i = i * i;
            for(int j = square_i; j <= n; j++){
                dp[j] = min(dp[j], dp[j - square_i] + 1);
            }
        }
        return dp[n];
    }
};

