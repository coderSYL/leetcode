// C++
// leetcode 838
// https://leetcode-cn.com/problems/push-dominoes/
// 队列辅助的BFS

class Solution {
public:
    string pushDominoes(string dominoes) {
    	int n = dominoes.size();
    	// 记录位置i的受力情况
    	vector<char> forces(n, '.');
    	// 记录位置i变成此受力的时间
    	vector<int> time(n, INT_MAX);
    	queue<int> q;
    	// 根据dominoes进行初始化
    	for(int i = 0; i < n; i++) {
    		forces[i] = dominoes[i];
    		if(dominoes[i] != '.') {
    			time[i] = 0;
    			q.push(i);
    		}
    	}
    	// 开始按时间利用BFS模拟多米诺骨牌推倒过程
    	int now = 0;
    	while(!q.empty()) {
	    	now++;
	    	int size = q.size();
	    	while(size--) {
	            int i = q.front();
	            q.pop();
	            if(forces[i] == '.') continue;
	    		int u = (forces[i] == 'L' ? -1 : 1 );
	    		int idx = i + u;
	    		if(idx < 0 || idx >= n) continue;
	    		if(time[idx] < now) continue;
	    		if(forces[idx] == '.')
	    			forces[idx] = forces[i];
	    		else if(forces[idx] != forces[i])
	    			forces[idx] = '.';
	    		time[idx] = now;
	    		q.push(idx);
	    	}
    	}
    	return string(forces.begin(), forces.end());
    }
};