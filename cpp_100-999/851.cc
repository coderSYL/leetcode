// C++
// leetcode 851
// https://leetcode-cn.com/problems/loud-and-rich/
// 方法二是自己写的，方法一是看了官方题解dfs后自己另外写的bfs
// 原来还有在函数里用function绑定lambda的写法，属实学到了

// 方法一
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    	int n = quiet.size();
    	vector<vector<int>> richerThan(n, vector<int>{});
    	for(auto& v : richer)
    		richerThan[v[1]].push_back(v[0]);
    	vector<int> res(n, -1);
    	function<int(int)> bfs = [&](int u) {
    		if(res[u] != -1) return res[u];
    		int x = u;
    		for(auto richerGuy : richerThan[u]) {
    			int local = bfs(richerGuy);
    			if(quiet[local] < quiet[x])
    				x = local;
    		}
    		res[u] = x;
    		return x;
    	};
    	for(int i = 0; i < n; i++)
    		bfs(i);
    	return res;
    }
};

// // 方法二：bfs
// class Solution {
// public:
// 	vector<vector<bool>> f;	// f[i][j] 为 true 表示：j肯定比i有钱
// 	vector<int> res;	// 返回值，初始化的值全为 -1
// 	vector<int> quiet_;
// 	int n;

// 	// 此函数返回(肯定不比第 u 人的穷的人)中最安静的人
// 	int bfs(int u) {
// 		// 之前算过了，直接返回
// 		if(res[u] != -1) return res[u];
// 		// 自己肯定不比自己穷
// 		int ret = u;
// 		for(int i = 0; i < n; i++) {
// 			// 不确定是否更有钱，过
// 			if(!f[u][i]) continue;
// 			// i 肯定比 u 有钱
// 			int one = bfs(i);
// 			if(quiet_[one] < quiet_[ret]) ret = one;
// 		}
//         res[u] = ret;
// 		return ret;
// 	}

//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//     	n = quiet.size();
//     	f.resize(n, vector<bool>(n, false));	// f[i][j] 为 true 表示 j 比 i的钱多
//     	for(auto& v : richer)
//     		f[v[1]][v[0]]= true;
//     	quiet_.swap(quiet);
//     	res.resize(n, -1);
//     	for(int i = 0; i < n; i++)
//     		bfs(i);
//     	return res;
//     }
// };