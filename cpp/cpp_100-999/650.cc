// C++
// leetcode 650
// https://leetcode-cn.com/problems/2-keys-keyboard/
// 


class Solution {
public:
    int minSteps(int n) {
    	int i = 2;
    	int res = 0;
    	unordered_map<int, int>	m;

    	// 统计质因数
    	while(n != 1) {
    		if(n % i == 0) {
    			n /= i;
    			m[i]++;
    		} else {
    			i++;
    		}
    	}


    	for(auto it = m.begin(); it != m.end(); it++) {
    		// it的第一项是质因数的底数a，第二项是指数b
    		// 让现有的字符个数扩充a倍的操作是，复制一次，粘贴 (a-1) 次，共a次操作
    		// 所以扩充a^b倍的总操作数是 a*b
    		res += it->first * it->second;
    	}

    	return	res;
    }
};