// C++
// leetcode 324
// https://leetcode.cn/problems/wiggle-sort-ii/

class Solution {
public:
	vector<int> nums;
	int n;

	int qSelect(int l, int r, int k) {
		if (l == r)
			return nums[l];
		int x = nums[(l+r) >> 1], i = l - 1, j = r + 1;
		while(i < j) {
			do i++;
			while (nums[i] < x);
			do j--;
			while (nums[j] > x);
			if(i < j)
				swap(i, j);
		}
		int cnt = j - l + 1;
		if (k <= cnt)
			return qSelect(l, j, k);
		// else
		return qSelect(j + 1, r, k - cnt);
	}

	void swap(int a, int b) {
		int c = nums[a];
		nums[a] = nums[b];
		nums[b] = c;
	}

    void wiggleSort(vector<int>& nums_) {
    	nums = nums_;
        n = nums_.size();
        int x = qSelect(0, n-1, (n+1) >> 1);
        int l = 0, r = n - 1, loc = 0;
        while (loc <= r) {
        	if (nums[loc] < x)
        		swap(loc++, l++);
        	else if (nums[loc] > x)
        		swap(loc, r--);
        	else
        		loc++;
        }
        int idx = 1;
        loc = n - 1;
        while (idx < n) {
        	nums_[idx] = nums[loc--];
        	idx += 2;
        }
        idx = 0;
        while (idx < n) {
        	nums_[idx] = nums[loc--];
        	idx += 2;
        }
    }
};



// // 方法二，就地作业
// class Solution {
// public:
// 	int n;

// 	int qSelect(vector<int>& nums, int l, int r, int k) {
// 		if (l == r)
// 			return nums[l];
// 		int x = nums[(l+r) >> 1], i = l - 1, j = r + 1;
// 		while(i < j) {
// 			do i++;
// 			while (nums[i] < x);
// 			do j--;
// 			while (nums[j] > x);
// 			if(i < j)
// 				swap(nums, i, j);
// 		}
// 		int cnt = j - l + 1;
// 		if (k <= cnt)
// 			return qSelect(nums, l, j, k);
// 		// else
// 		return qSelect(nums, j + 1, r, k - cnt);
// 	}

// 	void swap(vector<int>& nums, int a, int b) {
// 		int c = nums[a];
// 		nums[a] = nums[b];
// 		nums[b] = c;
// 	}

// 	int getIdx(int x) {
// 		return (2 * x + 1) % (n | 1);
// 	}

//     void wiggleSort(vector<int>& nums) {
//         n = nums.size();
//         int x = qSelect(nums, 0, n-1, (n+1) >> 1);
//         int l = 0, r = n - 1, loc = 0;
//         while (loc <= r) {
//         	if (nums[getIdx(loc)] > x) swap(nums, getIdx(loc++), getIdx(l++));
//             else if (nums[getIdx(loc)] < x) swap(nums, getIdx(loc), getIdx(r--));
//             else loc++;
//         }
//     }
// };