// C++
// leetcode 552
// https://leetcode-cn.com/problems/student-attendance-record-ii/
// 多种分类的dp

class Solution {
public:
    int checkRecord(int n) {
    	int res = 0;	// 全勤
    	long nn = 1000000007;
    	vector<long> endWithPA(n, 0);
    	vector<long> endWith1L(n, 0);
    	vector<long> endWith2L(n, 0);
    	vector<long> AendWithPA(n, 0);
    	vector<long> AendWith1L(n, 0);
    	vector<long> AendWith2L(n, 0);

    	endWithPA[0] = 1;
    	endWith1L[0] = 1;
    	endWith2L[0] = 0;
    	AendWithPA[0] = 1;
    	AendWith1L[0] = 0;
    	AendWith2L[0] = 0;

    	for(int i = 1; i < n; i++) {
    		long a = endWithPA[i - 1], b = endWith1L[i - 1], c = endWith2L[i - 1];
    		long e = AendWithPA[i - 1], f =AendWith1L[i -1], g =AendWith2L[i - 1];
    		endWithPA[i] = (a + b + c) %nn;
    		endWith1L[i] = a;
    		endWith2L[i] = b;
    		AendWithPA[i] = (a + b + c + e + f + g)%nn;
    		AendWith1L[i] = e;
    		AendWith2L[i] = f;
    	}

    	return	(int)((endWithPA[n-1] + endWith1L[n-1] + endWith2L[n-1] + AendWithPA[n-1] + AendWith1L[n-1] +AendWith2L[n-1]) % nn);
    }
};