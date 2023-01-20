// C++
// leetcode 1710
// https://leetcode.cn/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    	int cnt[1009];
    	memset(cnt, 0, sizeof(cnt));
    	for (int i = 0; i < boxTypes.size(); i++) {
    		cnt[boxTypes[i][1]] += boxTypes[i][0];
    	}

    	int res = 0;
    	for (int i = 1000; i >= 0 && truckSize > 0; i--) {
    		if (truckSize >= cnt[i]) {
    			res += i * cnt[i];
    		} else {
    			res += i * truckSize;
    		}
			truckSize -= cnt[i];
    	}
    	return res;
    }
};