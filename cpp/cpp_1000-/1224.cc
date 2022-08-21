// C++
// leetcode 1224
// https://leetcode.cn/problems/maximum-equal-frequency/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        // cnt 记录出现数字在 nums 中出现的次数
        // sum 记录cnt中的字数出现的次数
        int cnt[100009], sum[100009], mx = 0, res = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < nums.size(); i++) {
            // 计数，并更新
            int x = nums[i], cur = cnt[x];
            sum[cur]--;
            sum[++cur]++;
            cnt[x]++;

            // update mx
            mx = max(mx, cnt[x]);

            // check 环节
            if (mx == 1) {
                res = i + 1;
            } else if (mx * sum[mx] == i) {
                res = i + 1;
            } else if ((mx - 1) * (sum[mx - 1] + 1) == i) {
                res = i + 1;
            }
        }
        return res;
    }
};