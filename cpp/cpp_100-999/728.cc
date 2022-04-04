// C++
// leetcode 728
// https://leetcode-cn.com/problems/self-dividing-numbers/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
    	vector<int> res;
    	if(left == 1)
    		res.push_back(left++);

    	for (int i = left; i <= right; i++) {
    		int cur = i;
    		bool appeared[10], ok = true;
    		memset(appeared, 0, sizeof(appeared));
    		while(cur > 1) {
    			appeared[cur % 10] = true;
    			cur /= 10;
    		}
    		if(appeared[0])
    			ok = false;
    		else for(int j = 1; j < 10; j++) {
    			if(!appeared[j])
    				continue;
    			if(i % j != 0)
    				ok = false;
    		}
    		if(ok)
    			res.push_back(i);
    	}
    	return res;
    }
};