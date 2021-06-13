/*
 * C++
 * leetcode 278
 * url: https://leetcode-cn.com/problems/first-bad-version/
 * 经典二分法
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 特例，1没有前一个版本
        if(isBadVersion(1))
            return 1;
        // ret 应该满足  isBadVersion(ret) && (!isBadVersion(ret-1))
        int l = 1, r = n;
        int ret;
        while(l<=r){
            ret = l+ (r-l)/2;
            if(isBadVersion(ret)){
                if(!isBadVersion(ret-1))
                    return ret;
                else{
                    r =ret-1;
                }
            }else{
                l = ret+1;
            }
        }
        return -1;
    }
};