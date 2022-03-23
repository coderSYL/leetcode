// C++
// leetcode 88
// https://leetcode-cn.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int idx = m + n - 1, p1 = m - 1, p2 = n - 1;
    	while(idx >= 0) {
            if(p1 < 0) {
                nums1[idx--] = nums2[p2--];
            } else if(p2 < 0 || nums1[p1] > nums2[p2]) {
    			nums1[idx--] = nums1[p1--];
    		} else {
    			nums1[idx--] = nums2[p2--];
    		}
    	}
    	return;
    }
};