// C++
// leetcode 761
// https://leetcode.cn/problems/special-binary-string/

class Solution {
public:
    string makeLargestSpecial(string s) {
    	int n = s.size();
    	vector<string> tmp;
    	for (int i = 0, cur = 0, last = 0; i < n; i++) {
    		if (s[i] == '1')
    			cur++;
    		else
    			cur--;
    		if (cur == 0) {
    			tmp.push_back("1" + makeLargestSpecial(s.substr(last + 1, i - last - 1)) + "0");
    			last = i + 1;
    		}
    	}
    	sort(tmp.begin(), tmp.end());
    	string res = "";
    	for(int i = tmp.size() - 1; i >= 0; i--)
    		res += tmp[i];
    	return res;
    }
};