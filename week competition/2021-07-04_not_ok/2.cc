// C++
// 周赛 2021-07-04
// 2

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    	int n = dist.size();
    	// 计算出最后需要消灭怪物 i 的时间点，存储在 dist 里面

    	for(int i = 0; i < n; ++i) {
    		if(dist[i] % speed[i] == 0)
    			dist[i] -= speed[i];
    		dist[i] = dist[i] / speed[i];
    	}

    	sort(dist.begin(), dist.end());

    	for(int i = 0; i < n; ++i) {
    		if(dist[i] < i)
    			return i;
    	}

    	return n;
    }
};