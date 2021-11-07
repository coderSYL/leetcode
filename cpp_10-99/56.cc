// C++
// leetcode 56
// https://leetcode-cn.com/problems/merge-intervals/
// 先排序，然后合并


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector< vector<int>> res;
        for(int i = 0; i< intervals.size(); ){
            int j = i+1;
            int max = intervals[i][1];
            while(j < intervals.size() && intervals[j][0] <= max){
                if(max < intervals[j][1])
                	max = intervals[j][1];
                j++;
            }
            res.push_back({intervals[i][0], max});
            i = j;
        }
       
        return res;
    }
};