// C++
// leetcode 1742
// https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/

class Solution {
public:
	int get(int a) {
		int res = 0;
		while(a != 0) {
			res += a % 10;
			a /= 10;
		}
		return res;
	}

    int countBalls(int lowLimit, int highLimit) {
    	vector<int> cnt(46, 0);
    	for(int i = lowLimit; i <= highLimit; i++) {
    		cnt[get(i)]++;
    	}
    	int res = 0;
    	for(int i = 0; i < 46; i++) {
    		res = max(res, cnt[i]);
    	}
    	return res;
    }
};