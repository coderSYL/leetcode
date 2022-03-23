// C++
// leetcode 440
// https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/
// 偷三叶的思路

class Solution {
public:
	// 返回 [1, limit] 中以 x 为前缀的数的个数
	int getCnt(int x, int limit) {
		string a = to_string(x), b = to_string(limit);
		int n = a.size(), m = b.size(), k = m - n;
		int res = 0, u = stoi(b.substr(0, n));
		for(int i = 0; i < k; i++)
			res += (int)pow(10, i);
		if(u > x)
			res += pow(10, k);
		else if(u == x)
			res += limit - x * (int)pow(10, k) + 1;
		return res;
	}
	
    int findKthNumber(int n, int k) {
    	int res = 1;
    	while(k > 1) {
    		int cnt = getCnt(res, n);
    		if(cnt < k) {
    			k -= cnt;
    			res++;
    		} else {
    			k--;
    			res *= 10;
    		}
    	}
    	return res;
    }
};