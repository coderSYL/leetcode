// C++
// leetcode 40
// https://leetcode-cn.com/problems/combination-sum-ii/
// dfs回溯


class Solution {
public:
	vector<vector<int>>	res;
	vector<int>	v;
	int t_;	// target
	int n = 0;	// 记录种类个数

	void dfs(vector<int>& cs, vector<int>& nums, int cur, int sum) {
		// 合格
		if(sum == t_) {
			res.push_back(v);
			return;
		}
		// 录完了还不合格
        if(cur == n)
            return;

		int val = cs[cur];
		int num = nums[cur];

		dfs(cs, nums, cur + 1, sum);
		int done = 0;
		while(done < num) {
			if(sum + val > t_)
				break;
			sum += val;
			v.push_back(val);
			dfs(cs, nums, cur + 1, sum);
			done++;
		}

		// 回溯
        sum -= val * done;
		while(done > 0) {
			v.pop_back();
			done--;
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	t_ = target;

    	// 预处理candidates
    	// 去重（并没删除空间，而是覆盖，多余的空间留在结尾作废）
    	// 将个数录入cnt中
    	sort(candidates.begin(), candidates.end());
    	vector<int>	cnt;
    	int pre = candidates[0];
    	int curCnt = 1;
    	for(int i = 1; i < candidates.size(); i++) {
    		if(candidates[i] == pre)
    			curCnt++;
    		else {
    			candidates[n++] = pre;
    			cnt.push_back(curCnt);
    			curCnt = 1;
    			pre = candidates[i];
    		}
    	}
		candidates[n++] = pre;
    	cnt.push_back(curCnt);
        
    	// dfs回溯
    	dfs(candidates, cnt, 0, 0);

    	return	res;

    }
};