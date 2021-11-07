// C++
// leetcode 67
// https://leetcode-cn.com/problems/add-binary/
// 比最大size多一格


class Solution {
public:
    string addBinary(string a, string b) {
    	if(a == "0" && b == "0")
    		return	a;

    	bool oneMore = false;
    	int n = max(a.size(), b.size()) + 1;
    	char zero = '0';
    	char c[n];
    	for(int i = 0; i < n; i++) {
    		int cnt = oneMore;
    		if(a.size() > i)
    			if(a[a.size() - i - 1] == '1')
    				cnt++;
    		if(b.size() > i)
    			if(b[b.size() - i - 1] == '1')
    				cnt++;
    		if(cnt / 2 > 0)
    			oneMore = true;
    		else
    			oneMore = false;
    		cnt %= 2;
    		c[n - i - 1] = '0' + cnt;
    	}
    	if(c[0] == '0')
    		return	string(c + 1, c + n);
    	return	string(c, c + n);
    }
};