// C++
// leetcode 周赛 2021-07-24
// https://leetcode-cn.com/contest/biweekly-contest-57/problems/check-if-all-characters-have-equal-number-of-occurrences/
// 第一题

class Solution {
public:
    bool areOccurrencesEqual(string s) {
      if(s.size() == 0)
        return  true;
      map<char, int>  m;
      for(auto c : s) {
        ++m[c];
      }
      auto it = m.begin();
      int times = it->second;
      ++it;
      while(it != m.end()) {
        if(it->second != times)
          return false;
        ++it;
      }
      return true;
    }
};