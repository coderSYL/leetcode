// C++
// leetcode 282
// https://leetcode-cn.com/problems/expression-add-operators/
// 


class Solution {
private:
    int n;  // s.size()
    long t;  // target
    string s;   // 原字符串
    vector<string>  res;

    void dfs(int u, long pre, long cur, string ss) {
        if(u == n) {
            if(cur == t)
                res.push_back(ss);
            return;
        }

        for(int i = u; i < n; i++) {
            if(i != u && s[u] == '0') 
                break;

            long next = stol(s.substr(u, i - u + 1));

            if(u == 0) {
                // 是第一位，不能加符号
                dfs(i + 1, next, next, "" + to_string(next));
            } else {
                dfs(i + 1, next, cur + next, ss + "+" +  to_string(next));
                dfs(i + 1, -next, cur - next, ss + "-" +  to_string(next));
                long x = pre * next;
                dfs(i + 1, x, cur - pre + x, ss + "*" +  to_string(next));

            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        n = num.size();
        s = num;
        t = target;
        dfs(0, 0, 0, "");
        return  res;
    }
};