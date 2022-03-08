// C++
// leetcode 1601
// https://leetcode-cn.com/problems/maximum-number-of-achievable-transfer-requests
// 自己写了一版dfs，崩了，找好久没找到哪里错
// 最后还是看了三叶的然后顺着三叶的思路写了一遍呜呜呜

class Solution {
public:
	int getIdx(int a) {
		int res = 0;
		while(a) {
			if(a%2 == 1) res++;
			a /= 2;
		}
		return res;
	}

	bool check(int s, vector<vector<int>>& rs) {
		int n = rs.size();
		int state[20] = {0};
		int positiveNum = 0;
		for(int i = 0; i < n; i++) {
			if((s>>i) & 1 == 1) {
				if(++state[rs[i][1]] == 1) positiveNum++;
				if(--state[rs[i][0]] == 0) positiveNum--;
			}
		}
		return positiveNum == 0;
	}

    int maximumRequests(int n, vector<vector<int>>& requests) {
    	int END = 1<<(requests.size());
    	int res = 0;
    	for(int i = 0; i < END; i++) {
    		int idx = getIdx(i);
    		if(idx <= res) continue;
    		if(check(i, requests))
    			res = idx;
    	}
    	return res;
    }
};