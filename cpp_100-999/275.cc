// C++
// leetcode 275
// https://leetcode-cn.com/problems/h-index-ii/
// 经典二分

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int n = citations.size();
    	int h = INT_MIN;
    	int bad = INT_MAX;
    	int l = 1;
    	int r = n;
    	while(l <= r) {
    		int mid = l + (r - l);
    		if(citations[n - mid] < mid) {
                bad = mid;
    			r = mid -1;
    		} else {
    			h = mid;
    			l = mid + 1;
    		}
    	}
    	if(h == INT_MIN)
    		return bad - 1;
    	return h;
    }
};