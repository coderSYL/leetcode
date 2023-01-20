// C++
// leetcode 1775
// https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
    	// 预处理，统计每个数组的 1 ~ 6 有多少个
    	int cnt[2][7];
    	memset(cnt, 0, sizeof(cnt));
    	for(auto x : nums1) {
    		cnt[0][x]++;
    	}
    	for(auto x : nums2) {
    		cnt[1][x]++;
    	}

    	// 计算数组和
    	for (int i = 1; i <= 6; i++) {
    		// cout<<i<<" : "<<cnt[0][i]<<" : "<<cnt[1][i]<<endl;
    		cnt[0][0] += i * cnt[0][i];
    		cnt[1][0] += i * cnt[1][i];
    	}

    	// 确定哪个数组和比较大
    	int diff = cnt[0][0] - cnt[1][0];
    	int big = -1;
    	if (diff > 0) {
    		// cout<<"big is 0"<<endl;
    		big = 0;
    	} else if (diff == 0) {
    		return 0;
    	} else {
    		// cout<<"big is 1"<<endl;
    		big = 1;
    		diff = -diff;
    	}
    	// cout<<"diff is "<<diff<<endl;

    	// 
    	int res = 0;
    	for (int i = 5; i >= 1; i--) {
    		if (diff == 0)
    			break;
    		int t = cnt[big][1 + i] + cnt[1 - big][6 - i];
    		if (diff >= i * t) {
    			diff -= i * t;
    			res += t;
    		} else {
    			res += diff / i + (diff % i == 0 ? 0 : 1);
    			diff = 0;
    		}
    	}

        if (diff > 0) {
            // cout<<"CANT DIRECTLY"<<endl;
            return -1;
        }
    	return res;
    }
};