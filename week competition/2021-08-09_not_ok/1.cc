// C++
// leetcode 周赛 2021-08-08
// https://leetcode-cn.com/contest/weekly-contest-253/problems/check-if-string-is-a-prefix-of-array/
// 第一题

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
      int n = s.size();
      int wordNum = words.size();
      int now = 0;
      for(auto w : words) {
        if(now == n)
          return true;
        int add = w.size();
        if(now + add > n)
          return  false;
        int cnt = 0;
        while(cnt < add) {
          if(w[cnt] != s[now])
            return  false;
          cnt++;
          now++;
        }
      }
      if(now == n)
        return true;
      return false;
    }
};