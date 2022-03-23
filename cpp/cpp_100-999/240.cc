// C++
// leetcode 240
// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
// 


class Solution {
public:

	bool exist(vector<vector<int>>& m_, int l_x, int l_y, int r_x, int r_y, int target) {
		if(r_x < l_x || r_y < l_y)
			return	false;

		// 本框最小值
		int small = m_[l_x][l_y];
		// 本框最大值
		int big = m_[r_x][r_y];

		// target不在框中
		if(target > big || target < small)
			return	false;

		// target刚好在两点
		if(target == small || target == big)
			return	true;

		int mid_x = (l_x + r_x) / 2;
		int mid_y = (l_y + r_y) / 2;

		// 左上
		if(exist(m_, l_x, l_y, mid_x, mid_y, target))	return	true;
		// 右上
		if(exist(m_, l_x, mid_y + 1, mid_x, r_y, target))	return	true;
		// 右下
		if(exist(m_, mid_x + 1, mid_y + 1, r_x, r_y, target))	return	true;
		// 左下
		if(exist(m_, mid_x + 1, l_y, r_x, mid_y, target))	return	true;

		return	false;
	}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return	exist(matrix, 0, 0, m - 1, n - 1, target);
    }
};


// // 方法二：偷三叶的，把矩阵看作一个把右上角当成根的二叉搜索树
// class Solution {
// public:
	
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int x = 0, y = n - 1;
//         while(x < m && y >= 0) {
//         	if(matrix[x][y] > target) {
//         		// 比目标值大，往左子树走
//         		y--;
//         	} else if(matrix[x][y] == target) {
//         		return	true;
//         	} else {
//         		// 比目标值小，往右子树走
//         		x++;
//         	}
//         }

//         return	false;
//     }
// };