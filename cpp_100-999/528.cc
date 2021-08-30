// C++
// leetcode 528
// https://leetcode-cn.com/problems/random-pick-with-weight/
// 把前缀和数组记在类里
// 随机抽的时候，生成一个数，用二分在前缀和数组里找那个数

class Solution {
private:
    vector<int> sum;
    int n;
public:
    Solution(vector<int>& w) {
        n = w.size();
        sum.resize(n + 1);
        sum[0] = 0;
        for(int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + w[i];
        }
    }
    
    int pickIndex() {
        int val = rand() % sum[n];
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(sum[mid] <= val)
                l = mid;
            else
                r = mid - 1;
        }
        return  l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */