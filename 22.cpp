// c with stl(c++)
// 22
// https://leetcode-cn.com/problems/generate-parentheses/
// 


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res[n+1];
        int size[n+1];
        res[0].push_back("");
        size[0] = 1;
        res[1].push_back("()");
        size[1] = 1;
        for(int i = 2; i <=n; i++){ // 算出i = 2～n的答案
            // 先把 (i-1)的弄了
            for(int j = 0; j <size[i-1]; j++){
                res[i].push_back("(" + res[i-1][j] +")");
            }
            // 再把( p)q 给弄了
            for(int p = 0; p<i; p++){
                int q = i-1-p;
                for(int m =0; m< size[p]; m++){
                    for(int n = 0; n <size[q]; n++){
                        res[i].push_back("(" + res[p][m] +")"+res[q][n]);
                    }
                }
            }

            sort(res[n].begin(),res[n].end());
            size[i] = res[i].size();
            // cout<<i<<endl<<"before:"<<size[i]<<endl;
            for(int j = size[i] -1; j>0; j--){
                if(res[i][j] ==res[i][j-1]){
                    res[i].erase(res[i].begin()+j);
                }
            }
            size[i] = res[i].size();
            // cout<<i<<endl<<"after:"<<size[i]<<endl;
        }
        return res[n];
    }
};