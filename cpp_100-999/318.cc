// C++
// leetcode 318
// https://leetcode-cn.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int full = (1 << 26) - 1;

    int maxProduct(vector<string>& words) {
        int res = 0;
        map<int , int > m;  // hashval , length  
        for(auto s : words) {
            int length = s.size();
            int hashForThisString = 0;
            for(auto c : s) {
                hashForThisString = hashForThisString | (1 << (c - 'a'));
                if(hashForThisString == full)
                    break;
            }
            if(hashForThisString == full || length == 0)
                continue;
            for(auto [k, v] : m) {
                if((k & hashForThisString) == 0) {
                    // 没重复，可以试试
                    res = max(res, length * v);
                }
            }
            m[hashForThisString] = max(m[hashForThisString], length);
        }
        return  res;
    }
};