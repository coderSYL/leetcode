// C++
// leetcode 593
// https://leetcode.cn/problems/valid-square/

class Solution {
public:
	int getDis2(vector<int> &a, vector<int> &b) {
		int dx = a[0] - b[0];
		int dy = a[1] - b[1];
		return dx * dx + dy * dy;
	}

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    	map<int, int> d2;
    	d2[getDis2(p1, p2)]++;
    	d2[getDis2(p1, p3)]++;
    	d2[getDis2(p1, p4)]++;
    	d2[getDis2(p2, p3)]++;
    	d2[getDis2(p2, p4)]++;
    	d2[getDis2(p3, p4)]++;
    	
    	int minD2 = INT_MAX, maxD2 = INT_MIN;
    	for (auto &[k, v] : d2) {
    		minD2 = min(minD2, k);
    		maxD2 = max(maxD2, k);
    	}
    	if (minD2 * 2 != maxD2)
    		return false;
    	if (d2[minD2] != 4)
    		return false;

    	if (d2[maxD2] != 2)
    		return false;

    	return true;
    }
};