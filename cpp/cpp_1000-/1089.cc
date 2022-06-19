// C++
// leetcode 1089
// https://leetcode.cn/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
    	int cnt = 0, n = arr.size(), diff = 0;
    	for(int i = 0; i + cnt < n; i++) {
    		if(arr[i] == 0)
    			cnt++;
            diff = max(i + cnt - n + 1, 0);
    	}

    	// diff 预防的最典型例子
    	// 很多非0数字 + 末尾一个0
    	if(diff == 1) {
    		arr[n-1] = 0;
            cnt--;
    	}

    	// 填充
    	for(int i = n-1-diff, j = n-1-cnt-diff; j >= 0 && i != j; i--, j--) {
    		arr[i] = arr[j];
    		if(arr[j] == 0) {
    			arr[--i] = 0;
    		}
    	}
    }
};