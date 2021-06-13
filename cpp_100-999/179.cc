/*
 * C++
 * leetcode 179
 * url: https://leetcode-cn.com/problems/largest-number/
 * 利用sort的自定义算法，将nums中的数据重排
 * 注意全为0的情况特殊处理，判定方法：第一个数是否0
 */
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
        for(int num : nums){
            if(!(num==0&&res[0]=='0')) res+=to_string(num);
        }
        return res;
    }
};