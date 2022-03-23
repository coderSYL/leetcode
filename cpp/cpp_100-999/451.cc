// C++
// leetcode 451
// https://leetcode-cn.com/problems/sort-characters-by-frequency/
// 看注释

class Solution {
public:
    string frequencySort(string s) {
        // 预处理，把频率与 ASCII 绑定
        int fre[128] = {0};
        for(char c : s)
            fre[(int)c]++;
            
        // 把 pair< ASCII, freq>存入 vector，然后排序
        vector<pair<int,int>> temp;
        for(int i = 0; i < 128; ++i)
            if(fre[i])
                temp.push_back({i, fre[i]});
        sort(temp.begin(), temp.end(),[](const auto& A,const auto& B){
            return A.second > B.second;
        });

        // 排序完了，根据排序结果填装答案
        string res = "";
        for(auto p : temp)
            res += string(p.second, p.first);

        return res;
    }
};