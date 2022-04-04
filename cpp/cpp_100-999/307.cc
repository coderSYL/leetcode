// C++
// leetcode 307
// https://leetcode-cn.com/problems/range-sum-query-mutable/
// 树状数组初体验

class NumArray {
public:
	int n_;
	vector<int> tr;
	vector<int> nums_;

	int lowbit(int x){  return x & (-x);}

	// 在位置x增加u（下标从1开始
	void add(int x, int u) {
		for(int i = x; i <= n_; i += lowbit(i))
			tr[i] += u;
	}

	// 查询位置x
	int query(int x) {
		int res = 0;
		for(int i = x; i > 0; i -= lowbit(i))
			res += tr[i];
		return res;
	}

    NumArray(vector<int>& nums) {
    	nums_.swap(nums);
    	n_ = nums_.size();
    	tr.resize(n_ + 1);
    	for(int i = 0; i < n_; i++) {
    		add(i+1, nums_[i]);
    	}
    }
    
    void update(int index, int val) {
    	add(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
    	return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */