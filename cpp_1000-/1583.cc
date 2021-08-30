// C++
// leetcode 1583
// https://leetcode-cn.com/problems/count-unhappy-friends/
// 假设i与j配对，先建一个关系map， 每个i对应的set里包括所有比j更亲密的朋友
// 然后对每个人来进行判断，对i的每个更亲密朋友x，找x的亲密set里是否有i，如果有则i不开心，然后判断下一个i

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    	// 先见一个map，对应关系为 i : set{比i配对更亲密的好友}
    	unordered_map<int , unordered_set<int>> hm;
    	for(auto pp : pairs) {
    		int a = pp[0];
    		int b = pp[1];
    		for(auto f : preferences[a]) {
    			if(f == b)
    				break;
    			hm[a].insert(f);
    		}
    		for(auto f : preferences[b]) {
    			if(f == a)
    				break;
    			hm[b].insert(f);
    		}
    	}

    	int res = 0;
    	for(auto it = hm.begin(); it != hm.end(); it++) {
    		for(auto x : it->second) {
    			if(hm.find(x) != hm.end()){
    				// 如果存在
    				if(hm[x].find(it->first) != hm[x].end()) {
    					res++;
    					break;
    				}
    			}
    		}
    	}
    	return res;
    }
};