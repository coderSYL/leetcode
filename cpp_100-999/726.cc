// C++
// leetcode 726
// https://leetcode-cn.com/problems/number-of-atoms/
// 从后往前，遍历一次，一个栈用来存每对括号的倍数
// cur 存当前的倍数
// element 记录现在处理中的元素的字符串
// num 记录当前处理中的元素的个数，存进 map 时需要乘以 cur



#include <map>



class Solution {
public:
    string countOfAtoms(string formula) {
    	stack<int>	bei;
    	map<string, int> rbt;
    	string	element = "";
    	string  num = "";
    	int cur = 1;
    	for(auto it = formula.rbegin(); it != formula.rend(); it++) {
    		if(isdigit(*it)) {
    			num = *it + num;
    		} else if(*it == '(') {
    			cur = cur / bei.top();
    			bei.pop();
    		} else if(*it == ')') {
    			int times = (num == "" ? 1 : stoi(num));
    			num = "";
    			cur *= times;
    			bei.push(times);
    		} else {
    			// 字母
    			// 先加到 element 里
    			element = *it + element;
    			if(*it >= 'A' && *it <= 'Z') {	
    				// 元素首字母是大写的，如果出现大写字母，说明 element已经是一个完整的元素符号了
    				int addNum = (num == "" ? 1 : stoi(num)) * cur;
    				rbt[element] += addNum;
    				element = "";
    				num = "";
    			}
    		}
    	}
    	string res;
    	for(auto ele : rbt) {
    		res += ele.first;
            if(ele.second != 1)
                res += to_string(ele.second);
    	}
    	return res;
    }
};