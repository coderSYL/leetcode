// C++
// leetcode 384
// https://leetcode-cn.com/problems/shuffle-an-array/
// 借用了31.cc中的 nextPermutation()

class Solution {
private:
    void reverse(vector<int>& vv, int l, int r) {
        while(l < r) {
            swap( vv[l], vv[r]);
            ++l;
            --r;
        }
    }

    void nextPermutation(vector<int>& vv) {
        int n = vv.size();
        int p = n - 1;
        while(p >= 1 && vv[p - 1] >= vv[p])
            --p;
        if(p == 0) {
            reverse(vv, 0, n - 1);
            return;
        } else {
            int q = p;
            while(q + 1 < n && vv[q + 1] > vv[p - 1])
                ++q;
            swap(vv[p - 1], vv[q]);
            reverse(vv, p, n - 1);
        }
    }

	vector<int>	nums_;
	vector<int>	rand;
public:
    Solution(vector<int>& nums) {
    	nums_= nums;
    	rand = nums;
    }
    
    vector<int> reset() {
    	return	nums_;
    }
    
    vector<int> shuffle() {
    	nextPermutation(rand);
    	return	rand;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */