// C++
// leetcode 1818
// https://leetcode-cn.com/problems/minimum-absolute-sum-difference/
// 二分，参考了三叶

class Solution {
public:
	inline int ab(int a, int b) {
		return (a > b ? a-b : b-a);
	}

    inline int max_2(int a, int b) {
        return (a > b ? a : b);
    }
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    	int n = nums1.size();
    	vector<int>	sorted(nums1);
    	sort(sorted.begin(), sorted.end());
    	long res = 0;
    	long mmm = 0;
    	for(int i = 0; i < n; ++i) {
    		int a = nums1[i];
    		int b = nums2[i];
    		if(a == b)
    			continue;
    		int cha = ab(a, b);
    		res += cha;
    		int l = 0;
    		int r = n - 1;
    		while(l < r) {
    			int mid = l + (r - l + 1) / 2;
    			if(sorted[mid] <= b)
    				l = mid;
    			else
    				r = mid - 1;
    		}
    		int m = ab(sorted[r], b);
    		if(r + 1 < n)
    			m = min(m, ab(sorted[r + 1], b));
    		mmm = max_2(cha - m, mmm);
    	}
    	return (int)((res - mmm) % 1000000007);
    }
};