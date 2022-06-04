// C++
// leetcode 473
// https://leetcode.cn/problems/matchsticks-to-square/

class Solution {
public:
	int side_length;
	int cur[4];

	bool dfs(vector<int>& ms, int u) {
		if(u == ms.size())
			return true;
		int val = ms[u];
		for(int i = 0; i < 4; ++i) {
			bool jump = false;
			for(int j = 0; j < i; ++j)
				if(cur[i] == cur[j]) {
					jump = true;
					break;
				}
			if(jump)
				continue;
			cur[i] += val;
			if(cur[i] <= side_length && dfs(ms, u+1))
				return true;
			cur[i] -=val;
		}
		return false;
	}

    bool makesquare(vector<int>& ms) {
    	sort(ms.begin(), ms.end(), greater<int>());
    	memset(cur, 0, sizeof(cur));
    	int n = ms.size();
    	int sum = 0;
    	for(int i = 0; i < n; ++i) {
    		sum += ms[i];
    	}
    	if(sum % 4 != 0)
    		return false;
    	side_length = sum / 4;
    	return dfs(ms, 0);
    }
};