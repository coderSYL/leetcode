// C++
// leetcode 1449
// https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// 法二偷三叶的

// 更通用的解法
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int len = cost.size();
        vector<string> dp(target + 1,"#");
        dp[0] = "";
        // 因为i遍历的顺序是从小到大，就保证了整数的高位一定大于等于整数的低位，也就保证了整数最大
        for(int i = 1; i <= len; i++)
            for(int j = 1; j < target+1 ; j++){    
                if(j >= cost[i-1] && dp[j-cost[i-1]]!="#"){
                    dp[j] = CompareString(dp[j], to_string(i)+dp[j-cost[i-1]]);
                }
            }

        return (dp[target] == "#" ? "0" : dp[target]);
    }
private:
    string CompareString(const string& s1,const string& s2){
        int m = s1.size(), n = s2.size();
        if(m==n)return max(s1,s2);
        return m>n ? s1 : s2;
    }
};


// // 方法二，适合答案长度没超过int / long范围的
// class Solution {
// public:
//     string largestNumber(vector<int>& cost, int t) {
//         int len = cost.size();
//         vector<int> dp(t + 1, INT_MIN);
//         dp[0] = 0;
//         for(int i = 1; i <= 9; i++) {
//             int u = cost[i - 1];
//             for(int j = u; j <= t; j++) {
//                 dp[j] = max(dp[j], dp[j - u] + 1);
//             }
//         }
//         if(dp[t] < 0)
//             return  "0";
//         string res = "";
//         for(int i = 9, j = t; i >= 1; i--) {
//             int u = cost[i - 1];
//             while(j >= u && dp[j] == dp[j - u] + 1) {
//                 res += to_string(i);
//                 j -= u;
//             }
//         }
//         return  res;
//     }
// };