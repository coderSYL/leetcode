// C++
// leetcode 946
// https://leetcode.cn/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    	stack<int> stk;
    	int n = pushed.size();
    	int p = 0;
    	for (int i = 0; i < n; i++) {
    		while(!stk.empty() && stk.top() == popped[p]) {
    			stk.pop();
    			p++;
    		}
    		stk.push(pushed[i]);
    	}
    	return stk.empty();
    }
};