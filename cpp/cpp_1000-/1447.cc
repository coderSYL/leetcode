// C++
// leetcode 1447
// https://leetcode-cn.com/problems/simplified-fractions/

class Solution {
public:
	// 得到字符串 "[pre]/[deno]"
	string getString(int pre, int deno) {
		return to_string(pre) + "/" + to_string(deno);
	}

	// 判断x,y是否互质，互质则返回true，否则返回false
	bool relativelyPrime(int x, int y) {
		while(x != 1 && y != 1) {
			if(y < x) swap(x, y);
			// x < y
			if(y % x == 0) return false;
			y %= x;
		}
		return true;
	}

    vector<string> simplifiedFractions(int n) {
    	vector<string> res;
    	for(int numerator = 1; numerator < n; numerator++) {
    		for(int denominator = numerator + 1; denominator <= n; denominator++) {
    			if(!relativelyPrime(denominator, numerator)) continue;
    			res.push_back(getString(numerator, denominator));
    		}
    	}
    	return res;
    }
};