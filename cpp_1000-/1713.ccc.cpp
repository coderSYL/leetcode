// C++
// leetcode 1713
// https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/
// 把求解最长公共子序列LCS的问题  ->  求解最长上升子序列LIS的问题

class Solution {
public:
    int minOperations(vector<int>& t, vector<int>& arr) {
    	int n = t.size(), m = arr.size();
    	unordered_map<int , int> map;
    	for(int i = 0; i < n; ++i) {
    		map[ t[i] ] = i;
    	}

    	vector<int> list;
    	for(int i = 0; i < m; ++i) {
    		int x = arr[i];
    		if(map.find( x ) != map.end()) {
    			list.push_back( map[x] );
    		}
    	}

    	int len = list.size();

    	vector<int>	f(len);
    	vector<int>	g(len + 1, INT_MAX);
    	int max_common_size = 0;
    	for(int i = 0; i < len; ++i) {
    		int l = 0, r = len;
    		while(l < r) {
    			int mid = (l + r + 1)/ 2;
    			if(g[mid] < list[i])
    				l = mid;
    			else
    				r = mid - 1;
    		}
    		int clen = r + 1;
    		f[i] = clen;
    		g[clen] = min(g[clen], list[i]);
    		max_common_size = max(max_common_size, clen);
    	}
    	return	n - max_common_size;
    }
};