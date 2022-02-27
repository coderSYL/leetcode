// C++
// leetcode 1036
// https://leetcode-cn.com/problems/escape-a-large-maze/
// out of memory

class Solution {
public:
	int dirs[5] = {-1, 0, 1, 0, -1};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    	int s[1000000][1000000];
    	memset(s, 0, sizeof(s));
    	for(auto& pair : blocked) {
    		s[pair[0]][pair[1]] = -1;
    	}

    	s[source[0]][source[1]] = 1;	// 能到的地方为1
    	int tx = target[0], ty = target[1];
    	queue<long> q;
    	q.push((long)source[0] * 1000000 + source[1]);
    	while(!q.empty()) {
    		int x = q.front() / 1000000;
    		int y = q.front() % 1000000;
    		q.pop();
    		for(int i = 0; i < 4; ++i) {
    			int nx = x + dirs[i];
    			int ny = y + dirs[i + 1];
    			if(nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000) continue;
    			if(s[nx][ny] == 0) {
    				if(nx == tx && ny == ty) return true;
    				s[nx][ny] = 1;
    				q.push(nx * 1000000 + ny);
    			}
    		}
    	}
    	return false;
    }
};