// C++
// leetcode 526
// https://leetcode-cn.com/problems/beautiful-arrangement/
// 回溯，思路参考了题解

class Solution {
public:
	vector<bool>	visited;
	int res = 0;
	void backTrack(int n, int idx) {
		if(idx == n + 1) {
			res++;
			return;
		}
		for(int i = 1; i <= n; i++) {
			if(!visited[i] && (i%idx == 0 || idx%i == 0)) {
				visited[i] = true;
				backTrack(n, idx + 1);
				visited[i] = false;
			}
		}
	}

    int countArrangement(int n) {
    	visited.resize(n + 1, false);
    	backTrack(n, 1);
    	return	res;
    }
};