// C++
// leetcode 52
// https://leetcode-cn.com/problems/n-queens-ii/
// 位运算

class Solution {
public:
	long res = 0, upperlim;

	void dfs(long row, long ld, long rd) {
	    if (row != upperlim) {
	        long pos = upperlim & ~(row | ld | rd);
	        while (pos) {
	            long p = pos & -pos;
	            pos -= p;
	            dfs(row + p, (ld + p) << 1, (rd + p) >> 1);
	        }
	    } else
	        res++;
	}

    int totalNQueens(int n) {
    	upperlim = (1 << n) - 1;
    	dfs(0, 0, 0);
    	return	res;
    }
};