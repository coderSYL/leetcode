// C++
// leetcode 479
// https://leetcode-cn.com/problems/largest-palindrome-product/
// 思路偷三叶的

class Solution {
public:
	int MOD = 1337;
    int largestPalindrome(int n) {
        if(n == 1)
            return 9;
        int max = (int)pow(10, n) - 1;  // max 为 n位 的最大数，即n个9
        // 从大到小遍历，填充后面 n-1位，然后
        for(int i = max; i >= 0; i--) {
            long num = i, t = i;
            while(t != 0) {
                num = num * 10 + (t % 10);
                t /= 10;
            } // 循环完后num即为填充完毕后的回文长数字
            // 检查num是否可表示为两数乘积，能则返回
            for(long j = max; j * j >= num; j--) {
                if(num % j == 0)
                    return (int)(num % MOD);
            }
        }

        return -1; // 没找到
    }
};