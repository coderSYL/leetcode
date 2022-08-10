// C++
// leetcode 1331
// https://leetcode.cn/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    	int n = arr.size();
    	map<int, int> m;

    	// 录入数据
    	for (auto x : arr)
    		m[x] = 0;

    	// 排名
        int p = 1;
        for (auto &[k ,v] : m)
        	v = p++;

        // 填装答案
    	for (int i = 0; i < n; i++)
    		arr[i] = m[arr[i]];

    	return arr;
    }
};