// C++
// leetcode 1996
// https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game/

class Solution {
public:
	static bool cmp(long a, long b) {
		int aA, aD, bA, bD;
		getAttackAndDefense(a, aA, aD);
		getAttackAndDefense(b, bA, bD);
		if(aA != bA)
			return aA > bA;
		return aD > bD;
	}

	static long getIdx(int attack, int defense) {
		return ((long)attack) * 100010 + defense;
	}

	static void getAttackAndDefense(long idx, int &attack, int &defense) {
		attack = idx / 100010;
		defense = idx % 100010;
	}

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
    	int n = properties.size();
    	long ps[n];
    	for(int i = 0; i < n; i++) {
    		ps[i] = getIdx(properties[i][0], properties[i][1]);
    	}
    	sort(ps, ps+n, cmp);
    	int res = 0;
    	int m, tmp;
    	getAttackAndDefense(ps[0], tmp, m);
    	for(int i = 0; i < n; ) {
    		int j = i;
    		int attack,defense;
    		getAttackAndDefense(ps[i], attack, defense);
    		while(j < n) {
    			int jA, jD;
    			getAttackAndDefense(ps[j], jA, jD);
    			if(jA != attack)
    				break;
    			if(i != 0 && jD < m)
    				res++;
    			j++;
    		}
    		m = max(m, defense);
    		i = j;
    	}
    	return res;
    }
};