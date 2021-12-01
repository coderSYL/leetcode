// C++
// leetcode 48
// https://leetcode-cn.com/problems/rotate-image/

// 方法一，递归，每次旋转最外面一圈，然后往里递归
// class Solution {
// public:
// 	void rotate(vector<vector<int>>& matrix, int start,int stop){
// 		if(start>=stop)
// 			return;
// 		int temp = 0;
// 		for(int i = start; i<stop; i++){	//旋转一圈
// 			temp = matrix[start][i];
// 			matrix[start][i] = matrix[stop+start-i][start];
// 			matrix[stop+start-i][start] = matrix[stop][stop+start-i];
// 			matrix[stop][stop+start-i] = matrix[i][stop];
// 			matrix[i][stop] = temp;
// 		}
// 		rotate(matrix, start+1, stop-1);
// 	}

// 	void rotate(vector<vector<int>>& matrix) {
// 	        int size = matrix.size();
// 	        rotate(matrix, 0 , size-1);
// 	        return;
// 	}

// 方法二
class Solution {
public:
// 先对矩阵进行转置，然后每行都换，速度快了，但是内存花费差不多
    void rotate(vector<vector<int>>& matrix) {

        int size = matrix.size();
        int temp = 0, i = 0, j = 0, k = 0;

        for (i = 0 ; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        j = 0;
        k = size - 1;
        while (j < k) {
            for (i = 0 ; i < size; i++) {
                swap(matrix[i][j], matrix[i][k]);
            }
            j++;
            k--;
        }
        return;
    }
};