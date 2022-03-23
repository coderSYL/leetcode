// C++
// leetcode 2039
// https://leetcode-cn.com/problems/the-time-when-the-network-becomes-idle/

class Solution {
public:
	int N, M, idx = 0;
	vector<int> e, ne, he;
	void add(int a, int b) {
		e[idx] = b;
		ne[idx] = he[a];
		he[a] = idx++;
	}

	void doubleLink(int a, int b) {
		add(a, b);
		add(b, a);
	}

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    	// 建图
        N = patience.size();
        M = 2 * edges.size();
        he.resize(N, -1);
        e.resize(M);
        ne.resize(M);
        for(auto &p : edges) {
        	doubleLink(p[0], p[1]);
        }
        vector<int> once(N, INT_MAX);
        once[0] = 0;
        int done = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty() && done < N) {
        	int cur = q.front();
        	q.pop();
        	int now = once[cur] + 1;
        	for(int i = he[cur]; i != -1; i = ne[i]) {
        		int target = e[i];
        		if(once[target] < INT_MAX)
        			continue;
        		once[target] = now;
        		done++;
        		q.push(target);
        	}
        }
        int res = 0;
        for(int i = 1; i < N; i++) {
            int cur = once[i] * 2;
        	int lastMessage = (cur-1) / patience[i] * patience[i];
            // cout<<lastMessage<<" : "<<cur<<endl;
        	res = max(res, lastMessage + cur);
        }
        return res + 1;
    }
};