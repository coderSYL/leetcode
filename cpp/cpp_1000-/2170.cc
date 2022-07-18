// C++
// leetcode 2170
// https://leetcode.cn/problems/minimum-operations-to-make-the-array-alternating/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt[2][100009];
        memset(cnt, 0, sizeof(cnt));
        int n = nums.size();
        int p[2][2];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i++) {
        	int u = i & 1;
        	cnt[u][nums[i]]++;
        	if (p[u][0] == nums[i])
        		continue;
        	if (cnt[u][nums[i]] > cnt[u][p[u][0]]) {
        		
        		p[u][1] = p[u][0];
        		p[u][0] = nums[i];
        	} else if (cnt[u][nums[i]] > cnt[u][p[u][1]]) {
        		p[u][1] = nums[i];
        	}
        }
        // cout<<p[0][0]<<" , "<<p[0][1]<<endl;
        // cout<<p[1][0]<<" , "<<p[1][1]<<endl;
        if (p[0][0] == p[1][0]) {
        	return n - max(cnt[0][p[0][1]] + cnt[1][p[1][0]], cnt[0][p[0][0]] + cnt[1][p[1][1]]);
        }

        return n - cnt[0][p[0][0]] - cnt[1][p[1][0]];
    }
};