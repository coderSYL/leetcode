/*
 * C++
 * leetcode 474
 * url: https://leetcode-cn.com/problems/ones-and-zeroes/
 * f[k][i][j]表示 处理前k个string要求不超过i个0与j个1能得到的个数
 */

class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
    	int size = strs.size();
    	int cnt[size][2];
    	for(int i =0; i<size; i++){
    		int zero =0, one =0;
    		for(char c:strs[i]){
    			if(c== '0')
    				zero++;
    			else
    				one++;
    		}
    		cnt[i][0] = zero;
    		cnt[i][1] = one;
    	}	// 预处理完毕

    	int f[size+1][m+1][n+1];
		// 初始化为0
		memset(f, 0, sizeof(f[0]));
    	for(int k =1; k<=size; k++){
    		int zero = cnt[k-1][0], one = cnt[k-1][1];
    		for(int i =0; i<=m; i++){
    			for(int j=0; j<=n; j++){
    				// 不要第k件
    				int a =f[k-1][i][j];
    				// 要第k件
    				int b = (i>=zero && j>=one)? f[k-1][i-zero][j-one]+1:0;
    				f[k][i][j] = max(a,b);
    			}
    		}
    	}
    	return f[size][m][n];
    }
};