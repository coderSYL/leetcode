// C++
// leetcode 1769
// https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
	int abs(int a, int b) {
		return (a > b ? a- b : b - a);
	}
	
    vector<int> minOperations(string boxes) {
    	int n = boxes.size();
    	vector<int> res(n, 0);
    	for (int i = 0; i < n; i++) {
    		if (boxes[i] == '1') {
    			for (int j = 0; j < n; j++) {
    				res[j] += abs(i, j);
    			}
    		}
    	}
    	return res;
    }
};