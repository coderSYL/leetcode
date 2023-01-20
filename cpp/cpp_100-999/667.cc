// C++
// leetcode 667
// https://leetcode.cn/problems/beautiful-arrangement-ii/
// 思路偷三叶的

class Solution {
public:
    vector<int> constructArray(int n, int k) {
    	vector<int> res(n);
        k--;
    	int up = 1, down = n, times = k >> 1;
    	for(int i = 0; i < n; i++) {
    		if (i%2 == 1 && times > 0) {
    			times--;
    			res[i] = down--;
    		} else {
    			res[i] = up++;
    		}
    	}
		
    	if (k%2 == 1) {
    		swap(res[n-2], res[n-1]);
    	}
    	return res;
    }
};