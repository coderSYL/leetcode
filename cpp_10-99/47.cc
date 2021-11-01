// C++
// leetcode 47
// https://leetcode-cn.com/problems/permutations-ii/
// 效率不高


class Solution {
public:
	vector<int>	cnt;
	int kind;
	vector<int>	used;
	vector<int>	cur;
	vector<vector<int>>	res;
	int n;

	void dfs(vector<int>& nums, int lastProcessed, int start) {
		if(cur.size() == n) {
			res.push_back(cur);
			return;
		}

		int idx_local = start;
		for( ; idx_local < kind; idx_local++) {
			if(cnt[idx_local] > used[idx_local] && idx_local != lastProcessed)
				break;
		}
		
		if(idx_local == kind)
			return;

		int val = nums[idx_local];

		while(cnt[idx_local] > used[idx_local]) {
			// 每loop填装一个
			used[idx_local]++;
			cur.push_back(val);
			dfs(nums, idx_local, 0);
		}

		// 回溯
		while(!cur.empty() && cur.back() == val) {
			cur.pop_back();
			used[idx_local]--;
		}
		dfs(nums, lastProcessed, idx_local + 1);
	}


    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	// 预处理
    	n = nums.size();
    	sort(nums.begin(), nums.end());
    	int cur_cnt = 0;
    	int cur_val = nums[0];
    	kind = 0;
    	for(auto x : nums) {
    		if(x == cur_val) {
    			cur_cnt++;
    		} else {
    			cnt.push_back(cur_cnt);
    			cur_cnt = 1;
    			nums[kind] = cur_val;
    			kind++;
    			cur_val = x;
    		}
    	}

    	cnt.push_back(cur_cnt);
    	nums[kind] = cur_val;
    	kind++;
    	used.resize(kind, 0);
    	dfs(nums, kind, 0);
    	return	res;
    }
};