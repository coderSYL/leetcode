// C++
// leetcode 1104
// https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/
// 

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int line = 1;
        int node_this_line = 1;
        while(label >= node_this_line * 2) {
            ++line;
            node_this_line *=2;
        }
        if(line %2 == 0) {
            label = node_this_line * 3 - 1 - label;
        }
        vector<int> res(line);
        while(line >= 1) {
            // 用过一个line 与 label 确定号码
            if(line % 2 == 0) {
                // 偶数行，右到左
                res[line - 1] =  node_this_line * 3 - label - 1;
            } else {
                // 奇数行，左到右
                res[line - 1] = label; 
            }
            label /= 2;
            --line;
            node_this_line /= 2;
        }
        return  res;
    }
};