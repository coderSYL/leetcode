// C++
// leetcode 135
// https://leetcode-cn.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 2) return  n;
        vector<int> f(n);
        f[0] = 1;
        // 从左到右
        for(int i = 1; i < n; i++) {
            if(ratings[i - 1] < ratings[i])
                f[i] = f[i - 1] + 1;
            else
                f[i] = 1;
            // cout<<i<<" "<<f[i]<<endl;
        }
        // 从右到左
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1])
                f[i] = max(f[i], f[i + 1] + 1);
        }
        // 统计结果
        int res = 0;
        for(auto x : f)
            res += x;
        
        return  res;
    }
};