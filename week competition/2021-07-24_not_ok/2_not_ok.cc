// C++
// leetcode 周赛 2021-07-24
// https://leetcode-cn.com/contest/biweekly-contest-57/problems/the-number-of-the-smallest-unoccupied-chair/
// 第二题
// 不知道为啥

class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

    	int n = times.size();

    	int targetArrival = times[targetFriend][0];
    	sort(times.begin(), times.end(), cmp);
    	set<int>	free;
    	for(int i = 0; i < n; ++i) {
    		free.insert(i);
    	}

    	map<int, int>	desk;	// < time , desk num >
    	for(int i = 0; i < n; ++i) {
    		// 开始分配椅子了
    		int a = times[i][0];
    		int b = times[i][1];
    		auto it = desk.begin();
    		while(it != desk.end()) {
    			if(it->first <= a) {
    				free.insert(it->second);
    				++it;
    			} else {
    				desk.erase(desk.begin(), it);
    				break;
    			}
    		}
    		int chair_this_time = *(free.begin());
    		free.erase(free.begin());
    		desk[b] = chair_this_time;
    		if(a == targetArrival)
    			return chair_this_time;
    	}
    	return	-1;
    }
};