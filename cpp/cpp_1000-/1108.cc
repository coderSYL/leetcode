// C++
// leetcode 1108
// https://leetcode.cn/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
    	vector<char> tmp;
    	for(auto c : address) {
    		if(c != '.') {
    			tmp.push_back(c);
    		} else {
    			tmp.push_back('[');
    			tmp.push_back('.');
    			tmp.push_back(']');
    		}
    	}
    	return string(tmp.begin(), tmp.end());
    }
};