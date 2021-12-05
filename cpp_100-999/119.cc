// C++
// leetcode 119
// https://leetcode-cn.com/problems/pascals-triangle-ii/
// 滚动数组

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	if(rowIndex < 2)
    		return	 vector<int>(rowIndex + 1, 1);
    	int f[2][rowIndex + 1];
    	// 初始化，全为0
    	for(int i = 0; i <= rowIndex; i++) {
    		f[0][i] = 1;
    		f[1][i] = 1;
    	}
    	// 从第一行开始模拟
    	for(int i = 2; i <= rowIndex; i++) {
    		// 单次循环要做的事：从上一行的 i 个 算出 i + 1个
    		// 需要计算从index为 1 到 i - 1 的
    		// u : 本次目标数组index
    		// pre : 上一行数组index
    		int u = i % 2, pre = 1 - u;
    		for(int j = 1; j < i; j++) {
    			f[u][j] = f[pre][j] + f[pre][j - 1];
    		}
    	}
    	return	vector<int>(f[rowIndex%2], f[rowIndex%2] + (rowIndex + 1));
    }
};