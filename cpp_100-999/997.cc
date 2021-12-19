// C++
// leetcode 997
// https://leetcode-cn.com/problems/find-the-town-judge/

// 三叶的方法，出入度统计，更快
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for(auto& pair : trust) {
            f[pair[1]]++;
            f[pair[0]]--;
        }
        for(int i = 1; i <= n; ++i) {
            // 判定 i 是否是秘密法官
            if(f[i] == n - 1)
                return i;
        }
        return -1;
    }
};

// // 自己写的，邻接矩阵存，略慢
// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//     	bool f[n][n];	// f[i][j] 表示 j 信任 i
//     	memset(f, 0, sizeof(f));
//     	for(auto& pair : trust) {
//     		f[pair[1]-1][pair[0]-1] = true;
//     	}
//     	for(int i = 0; i < n; ++i) {
//     		// 判定 i + 1 是否是秘密法官
//     		bool isJudge = true;
//     		for(int j = 0; j < n; ++j) {
//     			if(i == j) continue;
//     			if(!f[i][j]) {
//     				isJudge = false;
//     				break;
//     			}
//     			if(f[j][i]) {
//     				isJudge = false;
//     				break;
//     			}
//     		}
//     		if(isJudge) return i + 1;
//     	}
//     	return -1;
//     }
// };