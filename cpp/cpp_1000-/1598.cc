// C++
// leetcode 1598
// https://leetcode.cn/problems/crawler-log-folder/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        // res 记录当前处于第几级目录
    	int res = 0;
        for (auto &s : logs) {
            if (s == "../") {
                // 若非 0 级目录，则返回上级目录
                if (res != 0)
                    res--;
            } else if (s != "./") {
                // 进入某子目录
                res++;
            }
        }
        return res;
    }
};