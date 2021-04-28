// c with stl(c++)
// 179
// https://leetcode-cn.com/problems/largest-number/
// 字符串相加的比较

class Solution {
public:

    static bool cmp(int a,int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa+sb>sb+sa;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res;
        for(auto num:nums){
            if(!(num==0&&res[0]=='0')) res+=to_string(num);
        }
        return res;
    }
};