// C++
// leetcode 436
// https://leetcode.cn/problems/find-right-interval/

class Solution {
public:
	struct Info
	{
		int idx;
		int start;
		Info() {};
		Info(int idx, int start) : idx(idx), start(start) {}
		bool operator<(const Info& a) const
        {	
        	if(start != a.start)
        		return start < a.start;
            return  idx < a.idx;
        }
	};

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
    	int n = intervals.size();
    	vector<int> res(n, -1);
    	vector<Info> tmp(n);
    	for(int i = 0; i < n; ++i) {
    		tmp[i].idx = i;
    		tmp[i].start = intervals[i][0];
    	}
    	sort(tmp.begin(), tmp.end());
    	for(int i = 0; i < n; ++i) {
    		int end = intervals[i][1];
    		int j = 0;
    		while(j < n && tmp[j].start < end)
    			j++;
    		if(j == n)
    			continue;
    		res[i] = tmp[j].idx;
    	}
    	return res;
    }
};