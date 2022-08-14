// C++
// leetcode 628
// https://leetcode.cn/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    	int f[2][3];	// f[0][i] min, f[1][i] max
    	for(int i = 0; i < 3; i++) {
    		f[0][i] = INT_MAX;
    		f[1][i] = INT_MIN;
    	}

    	for (auto x : nums) {
    		int tmp = 0;
    		if (f[0][1] != INT_MAX) {
    			tmp = f[0][1] * x;
    			f[0][2] = min(f[0][2], tmp);
    			f[1][2] = max(f[1][2], tmp);
    		}
    		if (f[1][1] != INT_MIN) {
    			tmp = f[1][1] * x;
    			f[0][2] = min(f[0][2], tmp);
    			f[1][2] = max(f[1][2], tmp);
    		}
    		if (f[0][0] != INT_MAX) {
    			tmp = f[0][0] * x;
    			f[0][1] = min(f[0][1], tmp);
    			f[1][1] = max(f[1][1], tmp);
    		}
    		if (f[1][0] != INT_MIN) {
    			tmp = f[1][0] * x;
    			f[0][1] = min(f[0][1], tmp);
    			f[1][1] = max(f[1][1], tmp);
    		}
    		f[0][0] = min(f[0][0], x);
    		f[1][0] = max(f[1][0], x);
    	}
    	return f[1][2];
    }
};