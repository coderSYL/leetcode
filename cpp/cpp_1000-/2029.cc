// C++
// leetcode 2029
// https://leetcode-cn.com/problems/stone-game-ix/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
    	int left[3] = {0};
        for(auto& x : stones) left[x%3]++;
    	if(left[0] == stones.size()) return true;
        int state = 0;
       	
       	return false;
    }
};