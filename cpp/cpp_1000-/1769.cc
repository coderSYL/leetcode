/*
 * C++
 * leetcode 1769
 * url: https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * 记录下初始时有球的位置
 * 再分别计算就 0 ~ size-1 再装入vector<int> ret 就完事了
 */

class Solution {
public:
	int ab(int a, int b){
		if(a>b)
			return a-b;
		return b-a;
	}

    vector<int> minOperations(string boxes) {
    	int size = boxes.size();
    	int position[size], p =0, temp =0;
    	vector<int> ret;
    	ret.resize(size);

    	for(int i =0; i<size; i++){
    		if(boxes[i] =='1'){
    			position[p++] = i;
    		}
    	}

    	for(int i =0; i<size; i++){
    		temp = 0;
    		for(int j = 0; j<p; j++)
    			temp += ab(i, position[j]);
    		ret[i] = temp;
    	}
    	return ret;
    }
};