// C++
// leetcode 686
// https://leetcode-cn.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    	int m = a.size(), n = b.size();
    	// 预处理，对不可能完成的部分情况直接返回-1
    	// 具体排除的情况是
    	// 1. b中出现了a中没有的字母
    	// 2. 26个字母，填充b所需要的a的数量最大与最小相差超过1
    	int cntA[26] = {0};
    	int cntB[26] = {0};
    	for(auto &c : a) cntA[c - 'a']++;
    	for(auto &c : b) cntB[c - 'a']++;
    	int MIN = INT_MAX, MAX = INT_MIN;
    	for(int i = 0; i < 26; ++i) {
    		int numInA = cntA[i];
    		int numInB = cntB[i];
    		if(numInA == 0) {
    			if(numInB == 0) continue;
    			else return -1;
    		}
    		MIN = min(numInB / numInA, MIN);
    		MAX = max(numInB / numInA, MAX);
            if(MAX - MIN > 1) -1;
    	}
    	
    	for(int beginp = 0; beginp < m; beginp++) {
    		int pa = beginp, pb = 0;
    		while(pb < n) {
    			if(a[pa] != b[pb]) {
    				break;
    			}
    			++pb;
    			++pa;
    			pa %= m;
    		}
    		// 通过检测
    		if(pb == n) {
    			return (n + beginp - 1) / m + 1;
    		}
    	}
    	return -1;
    }
};