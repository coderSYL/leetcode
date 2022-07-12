// C++
// leetcode 873
// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        unordered_map<int, int> getIdx;
        for(int i = 0; i < n; i++) {
            getIdx[arr[i]] = i;
        }
        memset(f, 0, sizeof(f));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int target = arr[i] + arr[j];
                if(getIdx.find(target) != getIdx.end()) {
                    // 存在
                    int k = getIdx[target];
                    if(f[i][j] == 0) {
                        f[j][k] = 3;
                    } else {
                        f[j][k] = f[i][j] + 1;
                    }
                    res = max(res, f[j][k]);
                }
            }
        }
        return res;
    }
};