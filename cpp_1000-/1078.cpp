// C++
// leetcode 1078
// https://leetcode-cn.com/problems/occurrences-after-bigram/
// 自己写的方法比较憨，看了题解学到了

class Solution {
private:
    vector<string> split(const string& s) {
        vector<string> res;
        stringstream ss(s);
        string curr;
        while(std::getline(ss, curr, ' ')) {
	        // std::getline() input - 流中获取数据 
			// str - 把数据转换成字符串 
			// delim - 分隔符
            res.push_back(curr);
        }
        return res;
    }

public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> strs = split(text);
        int n = strs.size();
        vector<string> res;
        for (int i = 0; i < n-2; ++i) {
            if (strs[i] == first && strs[i+1] == second) {
                res.push_back(strs[i+2]);
            }
        }
        return res;
    }
};