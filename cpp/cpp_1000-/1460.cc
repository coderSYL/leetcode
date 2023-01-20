// C++
// leetcode 1460
// https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
		// 两数组分别排序
    	sort(target.begin(), target.end());
    	sort(arr.begin(), arr.end());

		// 一一比对是否相等
    	for (int i = 0; i < arr.size(); i++) {
    		if (arr[i] != target[i])
    			return false;
    	}
		
    	return true;
    }
};