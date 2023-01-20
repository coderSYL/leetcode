// C++
// leetcode interview 17.19
// https://leetcode.cn/problems/missing-two-lcci/

class Solution {
public:
	void positionBack(vector<int>& arr, int x) {
		while (arr[x] != 0 && arr[x] != x + 1) {
			int pos = arr[x] - 1;
			swap(arr[x], arr[pos]);
		}
		return;
	}

    vector<int> missingTwo(vector<int>& nums) {
    	nums.push_back(0);
    	nums.push_back(0);
    	int n = nums.size();
    	int sum = n * (n + 1) / 2;
    	int real = n ^ (n-1);
    	for(int i = 0; i < n; i++) {
    		positionBack(nums, i);
    	}
    	vector<int> res(2);
    	int realSizeForRes = 0, p = 0;
    	while(realSizeForRes < 2) {
    		if(nums[p++] == 0)
    			res[realSizeForRes++] = p;
    	}
    	return res;
    }
};