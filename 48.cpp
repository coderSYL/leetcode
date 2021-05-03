/*
 * C++
 * leetcode48
 * url: https://leetcode-cn.com/problems/rotate-image/
 */

class Solution {
public:
// 方法一，递归，每次旋转最外面一圈，然后往里递归
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



// 先对矩阵进行转置，然后每行都换，速度快了，但是内存花费差不多
	void rotate(vector<vector<int>>& matrix) {

        int size = matrix.size();
        int temp = 0, i = 0, j = 0,k =0;

        for(i = 0 ; i<size; i++){
        	for(j =i+1; j<size; j++){
        		temp = matrix[i][j];
        		matrix[i][j] = matrix[j][i];
        		matrix[j][i] = temp;
        	}
        }

        
        j = 0;
        k = size-1;
    	while(j<k){
    		for(i = 0 ; i<size; i++){
	    		temp = matrix[i][j];
	    		matrix[i][j] = matrix[i][k];
	    		matrix[i][k] = temp;
	    	}
	    	j++;
	    	k--;
    	}
        return;
    }
};