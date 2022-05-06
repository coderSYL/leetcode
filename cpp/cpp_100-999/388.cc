// C++
// leetcode 388
// https://leetcode-cn.com/problems/longest-absolute-file-path/

class Solution {
public:
    int maxx(int a, int b) {
        return (a > b ? a : b);
    }

    int lengthLongestPath(string input) {
        int res = 0;
        stack<string> stk;
        int cur_size = 0;
        int n = input.size();
        for(int i = 0, j = 0; i < n;) {
            int tab_num = 0;
            bool isFile = false;
            while(i < n && input[i] == '\t') {
                tab_num++;
                i++;
            }
            j = i;
            while(j < n && input[j] != '\n') {
                if(input[j] == '.')
                    isFile = true;
                j++;
            }
            // cout<<i<<" :: "<<j<<endl;
            // 此时i为路径头，j为尾巴后面一位
            while(stk.size() > tab_num) {
                cur_size -= stk.top().size();
                stk.pop();
            }
            string tmp = input.substr(i, j-i);
            // cout<<tmp<<" size: "<<tmp.size()<<endl;
            // cout<<"now depth : "<<stk.size()<<" cur_size : "<<cur_size<<endl<<"-----"<<endl;
            stk.push(tmp);
            cur_size += j-i;
            i = j+1;
            if(isFile)
                res = maxx(res, cur_size + stk.size() - 1);
        }
        return res;
    }
};