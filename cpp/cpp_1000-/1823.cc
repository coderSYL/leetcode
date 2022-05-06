// C++
// leetcode 1823
// https://leetcode-cn.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
    	vector<int> info(n);
    	for(int i = 0; i < n; i++) {
    		info[i] = i+1;
    	}
    	int startPosition = 0;
    	while(info.size() != 1) {
    		int next = (startPosition + k - 1) % info.size();
    		info.erase(info.begin() + next);
    		startPosition = next;
    	}
    	return info[0];
    }
};