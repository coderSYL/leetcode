// C++
// leetcode 2100
// https://leetcode-cn.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> upAfter(n, 0);
        vector<int> down(n, 0);
        for(int i = 1; i < n; i++) {
        	if(security[i] <= security[i-1])
        		down[i] = down[i-1] + 1;
        	else
        		down[i] = 0;
        }
        for(int i = n - 2; i >= 0; i--) {
        	if(security[i] <= security[i+1])
        		upAfter[i] = upAfter[i+1] + 1;
        	else
        		upAfter[i] = 0;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
        	if(down[i] >= time && upAfter[i] >= time)
        		res.push_back(i);
        }
        return res;
    }
};