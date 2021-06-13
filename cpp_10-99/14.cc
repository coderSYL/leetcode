/**
 * C++
 * leetcode 14
 * url: https://leetcode-cn.com/problems/longest-common-prefix/
 * 使用ret 和 ret_size记录答案和答案长度
 * ret 初始化为strs[0] (if it exists)
 * 不断让ret与 strs中的 string比较，然后刷新ret 与ret_size
 * 若长度归0直接返回""
 */

class Solution {
public:
    int min(int a, int b){
        if(a<b)
            return a;
        return b;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size==0)
            return "";
        string ret = strs[0];
        int ret_size = ret.size();
        int temp =0;
        int i = 0;
        for(auto x:strs)
        {
            temp = min(ret_size, x.size());
            i = 0;
            while( i <temp)
            {
                if(ret[i] == x[i])
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
            if(i<ret_size)
            {
                ret_size = i;
                ret = ret.substr(0,ret_size);
            }
            if(ret_size==0)
                break;
        }
        return ret;
    }
};