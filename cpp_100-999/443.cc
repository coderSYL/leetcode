// C++
// leetcode 443
// https://leetcode-cn.com/problems/string-compression/
// 一遍循环，见注释

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1)
            return  1;
        int p = 0;  // 待处理的位置
        int res = 0;    // 返回值，下一个需要填写的位置
        while(p < n) {
            // 每轮统计一个字符与它的个数
            char c = chars[p];
            int cnt = 0;
            while(p < n && chars[p] == c) {
                p++;
                cnt++;
            }

            // 填充字符部分
            chars[res] = c;
            res++;

            // 如果只有一个，则不需要压缩，过
            if(cnt == 1)
                continue;

            // 填充数字部分
            int l = res;
            while(cnt > 0) {
                int temp = cnt%10;
                chars[res] = temp + 48;
                cnt /= 10;
                res++;
            }
            int r = res - 1;
            while(l < r) {
                swap(chars[l], chars[r]);
                l++;
                r--;
            }
        }
        return  res;
    }
};