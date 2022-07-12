// C++
// leetcode 1200
// https://leetcode.cn/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    	sort(arr.begin(), arr.end());
    	int n = arr.size();
    	vector<vector<int>> res;
    	res.push_back(vector<int>{arr[0], arr[1]});
    	int cur = arr[1] - arr[0];
    	for(int i = 2; i < n; i++) {
    		int x = arr[i] - arr[i - 1];
    		if(x < cur) {
    			res.clear();
    			res.push_back(vector<int>{arr[i-1], arr[i]});
    			cur = x;
    		} else if (x == cur) {
    			res.push_back(vector<int>{arr[i-1], arr[i]});
    		}
    	}
    	return res;
    }
};