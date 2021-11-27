// C++
// leetcode 519
// https://leetcode-cn.com/problems/random-flip-matrix/

class Solution {
private:
    int leftNum_;
    unordered_map<int, int>    map;
    int m_, n_;
public:
    Solution(int m, int n) {
        m_ = m;
        n_ = n;
        leftNum_ = m * n;
    }
    
    vector<int> flip() {
        int idx = rand() % leftNum_;
        leftNum_--;
        int good;
        if(map.find(leftNum_) == map.end())
            good = leftNum_;
        else
            good = map[leftNum_];

        if(map.find(idx) == map.end()) {
            // 不存在，则可返回，并且标记
            map[idx] = good;
        } else {
            // 存在，返回存的数，并且把存的数换一换
            int tmp = map[idx];
            map[idx] = good;
            idx = tmp;
        }
        return  vector<int>{idx / n_, idx % n_};
    }
    
    void reset() {
        leftNum_ = m_ * n_;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */