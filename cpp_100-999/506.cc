// C++
// leetcode 506
// https://leetcode-cn.com/problems/relative-ranks/
// 存起来，然后排序

class Solution {
public:
    struct Node
    {
        int score_;
        int idx_;
        Node(int score, int idx) : score_(score), idx_(idx) {}
        // 分越高，Node越小
        bool operator<(const Node& a) const {
            return  score_ > a.score_;
        }
    };

    vector<string> findRelativeRanks(vector<int>& score) {
        vector<Node> v;
        for(int i = 0; i < score.size(); i++) {
            v.push_back(Node(score[i], i));
        }
        sort(v.begin(), v.end());
        vector<string> res(score.size());
        for(int i = 0; i < score.size(); i++) {
            int idx = v[i].idx_, ranking = i + 1;
            if(ranking > 3) {
                res[idx] = to_string(ranking);
            } else if(ranking == 1) {
                res[idx] = "Gold Medal";
            } else if(ranking == 2) {
                res[idx] = "Silver Medal";
            } else if(ranking == 3) {
                res[idx] = "Bronze Medal";
            }
        }
        return res;
    }
};