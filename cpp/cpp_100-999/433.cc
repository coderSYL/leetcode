// C++
// leetcode 433
// https://leetcode-cn.com/problems/minimum-genetic-mutation/
// 由于涉及到的基因序列都是8个字符，并且每个字符都有4种可能
// 4 = 2 ^ 2，2*8 = 16位数字可以表示所有的序列可能

class Solution {
public:
	map<char, int> toInt;
	bool Initialized = false;

	void ini() {
		toInt['A'] = 0;
		toInt['T'] = 1;
		toInt['G'] = 2;
		toInt['C'] = 3;
	}

	int getIdx(string &s) {
		int ret = 0;
		for(int i = 0; i < 8; i++) {
			int u = toInt[s[i]];
			ret |= (u<<(2*i));
		}
		return ret;
	}

	vector<int> getNeighboor(int idx) {
		vector<int> ret;
		for(int i = 0; i < 16; i += 2) {
			int u = 3 & (idx >> i);
			for(int j = 0; j < 4; j++) {
				if(j == u)
					continue;
				int tmp = idx & (~(3 << i));
				tmp |= (j << i);
				ret.push_back(tmp);
			}
		}
		return ret;
	}

    int minMutation(string start, string end, vector<string>& bank) {
    	if(!Initialized) {
    		Initialized = true;
    		ini();
    	}

    	unordered_map<int, int> m; // <idx, step>

    	for(auto & s : bank) {
    		m[getIdx(s)] = INT_MAX;
    	}

    	int origin = getIdx(start), target = getIdx(end);
    	if(m.find(target) == m.end())
    		return -1;
    	m[origin] = 0;
    	queue<int> q;
    	q.push(origin);

    	while(!q.empty()) {
    		int cur = q.front();
    		int thisStep = m[cur] + 1;
    		q.pop();
    		vector<int> canReach = getNeighboor(cur);
    		for(auto & next : canReach) {
    			if(m.find(next) == m.end() || m[next] != INT_MAX) {
    				continue;
    			}
    			q.push(next);
    			if(next == target)
    				return thisStep;
    			m[next] = thisStep;
    		}
    	}
    	return -1;
    }
};