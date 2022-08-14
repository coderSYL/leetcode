// C++
// leetcode 768
// https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/

class Solution {
public:

    int maxChunksToSorted(vector<int>& arr) {
    	int n = arr.size();
    	vector<int> mn(n);
    	vector<int> mx(n);
    	mx[0] = arr[0]; mn[n - 1] = arr[n - 1];

    	for (int i = 1; i < n; i++) {
    		mx[i] = max(mx[i - 1], arr[i]);
    		mn[n - 1 - i] = min(mn[n - i], arr[n - 1 - i]);
    	}

    	int res = 1;
    	for (int i = 1; i < n; i++) {
    		if (mx[i - 1] <= mn[i])
    			res++;
    	}
    	return res;
    }
};