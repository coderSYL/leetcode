// C++
// leetcode 556
// https://leetcode.cn/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
    	int nn = n;
    	vector<int> nums;
    	while (n) {
    		nums.push_back(n % 10);
    		n /= 10;
    	}
    	n = nums.size();
    	int p = n - 1;
    	reverse(nums, 0, p);

    	while(p >= 1 && nums[p - 1] >= nums[p])
            --p;
        if(p == 0) {
            reverse(nums, 0, n - 1);
        } else {
            int q = p;
            while(q + 1 < n && nums[q + 1] > nums[p - 1])
                ++q;
            swap(nums[p - 1], nums[q]);
            reverse(nums, p, n - 1);
        }


        long res = 0;
        for(int i = 0; i < n; i++) {
        	res = res * 10 + nums[i];
        }
        // cout<<res<<endl;
        if (res > (long) INT_MAX)
        	return -1;
        n = (int)res;
        if(n <= nn)
        	return -1;
        return n;
    }

    void reverse(vector<int> &arr, int l, int r) {
    	int tmp;
    	while(l < r) {
    		tmp = arr[l];
    		arr[l] = arr[r];
    		arr[r] = tmp;
    		l++;
    		r--;
    	}
    }
};