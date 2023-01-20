// C++
// leetcode 2391
// https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        map<char, int> getIdx;
        getIdx['M'] = 0;
        getIdx['P'] = 1;
        getIdx['G'] = 2;
        vector<vector<int>> cnt(3, vector<int>(n, 0));
        int end[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
        	for (auto c : garbage[i]) {
        		cnt[getIdx[c]][i]++;
        	}
        	for (int j = 0; j < 3; j++) {
        		if (cnt[j][i] != 0)
        			end[j] = i;
        	}
        }
        int res = 0;
        for (int i = 0; i < 3; i++) {
        	res += cnt[i][0];
        	for (int j = 1; j <= end[i]; j++) {
        		res += cnt[i][j] + travel[j - 1];
        	}
        }
        return res;
    }
};