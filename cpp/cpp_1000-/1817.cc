// C++
// leetcode 1817
// https://leetcode.cn/problems/finding-the-users-active-minutes/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    	vector<int> ans(k, 0);
    	set<int> uNum;
    	for (int i = 0; i < logs.size(); i++) {
    		// int userID = , time = logs[i][1];
    		uNum.insert(logs[i][0]);
    	}
    	int userID2 = uNum.size();
    	map<int, int> getID2;
    	int idx = 0;
    	set<int> cnt[userID2];
    	for (int i = 0; i < logs.size(); i++) {
    		int userID = logs[i][0], time = logs[i][1];
    		auto it = getID2.find(userID);
    		if (it == getID2.end()) {
    			// 没录入，当场给它录入
    			getID2[userID] = idx++;
    		}
    		int ID2 = getID2[userID];
    		cnt[ID2].insert(time);
    	}
    	for (int i = 0; i < userID2; i++) {
    		ans[cnt[i].size() - 1]++;
    	}
    	return ans;
    }
};