// C++
// leetcode 816
// https://leetcode.cn/problems/ambiguous-coordinates/

class Solution {
public:
	vector<string> left, right;
	string s;
	int n;
	void set(int point) {
		// [0, point)
		// [point, n)
		left.clear();
		right.clear();
		
		for (int i = 1; i < point; i++) {
			// [0, i) + "." + [i, point)
			if (i > 1 && s[0] == '0')
				continue;
			if (s[point - 1] == '0')
				continue;
			left.push_back(s.substr(0, i) + "." + s.substr(i, point - i));
		}
        if (point == 1 || s[0] != '0')
			left.push_back(s.substr(0, point));

		
		for (int i = point + 1; i < n; i++) {
			// [point, i) + "." + [i, n)
			if (i > point +1 && s[point] == '0')
				continue;
			if (s[n-1] == '0')
				continue;
			right.push_back(s.substr(point, i - point) + "." + s.substr(i, n - i));
		}
        if (point == n - 1 || s[point] != '0')
			right.push_back(s.substr(point, n - point));
	}

    vector<string> ambiguousCoordinates(string s_) {
    	vector<string> res;
    	s = s_.substr(1, s_.size() - 2);
    	n = s.size();

    	for (int i = 1; i < n; i++) {
    		set(i);
    		if (left.empty() || right.empty())
    			continue;
    		for (auto s1 : left) {
    			for (auto s2 : right) {
    				res.push_back("(" + s1 + ", " + s2 + ")");
    			}
    		}
    	}

    	return res;
    }
};