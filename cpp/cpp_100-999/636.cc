// C++
// leetcode 636
// https://leetcode.cn/problems/exclusive-time-of-functions/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        vector<int> cpu;
        int cur = -1;

        for (auto &s : logs) {
            // 解析日志 s
            int nn = s.size(), p = 0;
            while(s[p] != ':')
                p++;
            int idx = stoi(s.substr(0, p++));
            char c = s[p];
            while(s[p] != ':')
                p++;
            int val = stoi(s.substr(++p));

            // 入
            if (c == 's') {
                // 原本非空
                if (!cpu.empty()) {
                    res[cpu.back()] += val - cur;
                }
                cpu.push_back(idx);
            } else {
            // 出
                val++;
                res[cpu.back()] += val - cur;
                cpu.pop_back();
            }
            cur = val;
        }

        return res;
    }
};