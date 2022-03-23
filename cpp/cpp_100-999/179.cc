// C++
// leetcode 179
// https://leetcode-cn.com/problems/largest-number/
// 利用sort的自定义算法，将nums中的数据重排
// 注意全为0的情况
// 因为别人的比我简洁多了，所以偷了，代码偷自 https://leetcode-cn.com/u/littletime_cc/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for(auto x : nums) vs.push_back(to_string(x));
        sort(vs.begin(),vs.end(),[](const auto& A,const auto& B){
            return A + B > B + A;
        });
        string ans;
        for(const auto& x : vs) ans += x;
        return ans[0] == '0' ? "0" : ans; 
    }
};