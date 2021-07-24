// C++
// leetcode 周赛 2021-07-24
// https://leetcode-cn.com/contest/biweekly-contest-57/problems/describe-the-painting/
// 第三题

class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		if(a[0] != b[0])
			return a[0] < b[0];
		return a[1] < b[1];
	}


    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    	sort(segments.begin(), segments.end(), cmp);
    	int n = segments.size();
    	int fill = 0;
    	for(int i = 0; i < n; i++) {
    		
    	}
    }
};