// C++
// leetcode 150
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
// 遇上数字就压栈，遇上符号就提取两个数字然后计算，再压栈

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	vector<int> stk;
    	int n = -1;
    	for (auto & s : tokens) {
    		if(s.size() != 1) {
    			n = stoi(s);
    			stk.push_back(n);
    			continue;
    		}
            
    		switch (s[0]) {
    		case '+':
    			n = stk.size();
    			stk[n-2] += stk[n-1];
    			stk.pop_back();
    			break;
    		case '-':
    			n = stk.size();
    			stk[n-2] -= stk[n-1];
    			stk.pop_back();
    			break;
    		case '*':
    			n = stk.size();
    			stk[n-2] *= stk[n-1];
    			stk.pop_back();
    			break;
    		case '/':
    			n = stk.size();
    			stk[n-2] /= stk[n-1];
    			stk.pop_back();
    			break;
    		default:
    			n = stoi(s);
    			stk.push_back(n);
    		}
    	}

    	return stk[0];
    }
};