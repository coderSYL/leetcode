// C++
// leetcode 798
// https://leetcode-cn.com/problems/smallest-rotation-with-highest-score/

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> c(n, 0);
        for(int i = 0; i < n; i++) {
            int a =(i - (n - 1) + n) % n, b = (i - nums[i] + n) % n;
            if(n - 1 >= nums[i]) {
                c[a]++;
                if(b < n-1) c[b+1]--;
            } else {
                c[0]++;
                c[b+1]--;
                c[a]++;
            }
        }
        int res = 0, maxScore = c[0];
        for(int i = 1; i < n; i++) {
            c[i] += c[i-1];
            if(c[i] > maxScore) {
                maxScore = c[i];
                res = i;
            }
        }
        return res;
    }
};