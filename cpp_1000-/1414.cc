// C++
// leetcode 1414
// https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
    	// 找到数列中靠近k的那两个数
    	int first = 1, second = 1;
    	while(first + second  <= k) {
    		first += second;
    		swap(first, second);
    	}
    	// 每次都优先用大的
        int res = 0;
    	while(k > 0) {
    		res += k / second;
    		k %= second;;
    		second -= first;
    		swap(first, second);
    	}
    	return res;
    }
};