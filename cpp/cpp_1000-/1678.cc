// C++
// leetcode 1678
// https://leetcode.cn/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string command) {
    	vector<char> res;
    	for (int i = 0; i < command.size(); i++) {
    		if (command[i] == 'G') {
    			res.push_back('G');
    		} else if (command[i + 1] == ')') {
    			res.push_back('o');
    			i++;
    		} else {
    			res.push_back('a');
    			res.push_back('l');
    			i += 3;
    		}
    	}
    	return string(res.begin(), res.end());
    }
};