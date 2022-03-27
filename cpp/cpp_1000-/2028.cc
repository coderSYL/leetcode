// C++
// leetcode 2028
// https://leetcode-cn.com/problems/find-missing-observations/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = (m + n) * mean;
        for(auto & x : rolls)
        	sum -= x;
        if(sum > 6 * n || sum < n)
        	return vector<int>{};
        // cout<<sum<<endl;
        vector<int> res(n, 1);
        sum -= n;
        for(auto & x : res) {
        	if(sum >= 5) {
        		sum -= 5;
        		x += 5;
        	} else if(sum > 0) {
        		x += sum;
        		sum = 0;
        	} else {
        		break;
        	}
        }
        return res;
    }
};