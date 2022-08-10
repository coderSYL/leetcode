// C++
// leetcode 899
// https://leetcode.cn/problems/orderly-queue/

class Solution {
public:
    string orderlyQueue(string s, int k) {
    	int n = s.size();

    	if (k == 1) {
    		int p = 0, x, y;
    		for(int i = 1; i < n; i++) {
    			x = p;
    			y = i;
    			bool ok = false;

    			for (int j = 0; j < n; j++) {
    				if (s[x] < s[y]) {
    					ok = false;
    					break;
    				} else if (s[x] > s[y]) {
    					ok = true;
    					break;
    				}
    				x = (x + 1) % n;
    				y = (y + 1) % n;
    			}

    			if (ok) {
    				p = i;
    			}
    		}
    		if (p == 0)
    			return s;
    		return s.substr(p) + s.substr(0, p);
    	}

    	char tmp[n];
    	for (int i = 0; i < n; i++) {
    		tmp[i] = s[i];
    	}
    	sort(tmp, tmp + n);
    	return string(tmp, tmp + n);
    }
};