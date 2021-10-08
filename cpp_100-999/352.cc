// C++
// leetcode 352
// https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/
// 用一个set来存原始数据，每次需要取出时重新造一个


class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int val) {
        s.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        if(s.empty())
            return  res;
        int first = *(s.begin()), second = first - 1;
        for(auto x : s) {
            if(x == second + 1) {
                second++;
            } else {
                res.push_back(vector<int>{first, second});
                first = x;
                second = first;
            }
        }
        res.push_back(vector<int>{first, second});
        return  res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */