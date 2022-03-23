// C++
// leetcode 71
// https://leetcode-cn.com/problems/simplify-path/

class Solution {
private:
    
public:
    string simplifyPath(string path) {
        vector<string> stk;

        int start = 0, idx = start;
        while(idx < path.size()) {
            // 寻找使得path[start, idx)为下一个目录
            start = idx;
            while(start < path.size() && path[start] == '/')
                start++;
            idx = start;
            while(idx < path.size() && path[idx] != '/')
                idx++;
            if(start == path.size())
                break;
            // 至此，path[start, idx)为下一个符合条件的目录

            // 判断这一次的目录，并作出相应操作
            if(idx == start + 1 && path[start] == '.') {
                // "."  当前目录，啥也不做
            } else if(idx == start + 2 && path[start] == '.' && path[start + 1] == '.') {
                // ".." 返回上一级目录，如果此时非根目录，则stk出栈一次
                if(!stk.empty())
                    stk.pop_back();
            } else {
                // 是一个合格的目录，可以录入stk
                stk.push_back(path.substr(start, idx - start));
            }
        }
        // 构造结果的字符串
        string res = "";
        if(stk.size() == 0) {
            res = "/";
        } else {
            for(auto s : stk)
                res += "/" + s;
        }
        return  res;
    }
};