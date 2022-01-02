// C++
// leetcode 846
// https://leetcode-cn.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    	if(hand.size() % groupSize != 0) return false;
    	map<int, int> cnt;
    	for(auto &x : hand) {
    		cnt[x]++;
    	}
    	int turn = hand.size() / groupSize;
    	while(turn-- > 0) {
    		// 每一轮先找到一个最小的，然后从它开始减一，如果减不动则g
    		auto it = cnt.begin();
    		while(it->second <= 0)
    			it++;
    		int start = it->first;
            cnt.erase(cnt.begin(), it); // 清除前面全为0的项，减少mapsize，稍微加速搜索
    		for(int i = start; i < start +groupSize; ++i) {
    			if(cnt[i]-- <= 0) return false;
    		}
    	}
    	return true;
    }
};