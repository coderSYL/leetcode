// C++
// leetcode 周赛 2021-07-18
// https://leetcode-cn.com/contest/weekly-contest-250/problems/maximum-genetic-difference-query/
// 第四题

class Solution {
public:
    inline int max_2(int a, int b) {
        return (a > b ? a : b);
    }
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int queriesSize = queries.size();
        vector<int> res(queriesSize);
        for(int i = 0; i < queriesSize; ++i) {
            int zero = queries[i][0];
            int one = queries[i][1];
            int temp = -1 ;
            while(zero != -1){
                temp = max_2(temp, zero ^ one);
                zero = parents[zero];
            }
            res[i] = temp;
        }
        return  res;
    }
};