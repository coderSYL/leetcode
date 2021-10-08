// C++
// leetcode 187
// https://leetcode-cn.com/problems/repeated-dna-sequences/
// 

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        int end = n - 10;
        unordered_map<string, int>  m;
        for(int i = 0; i <= n - 10; i++) {
            m[s.substr(i, 10)]++;
        }
        vector<string>  res;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second > 1)
                res.push_back(it->first);
        }
        return  res;
    }
};

// 方法二
// class Solution {
// public:
//     map<char, int>  m = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};
//     map<int, char>  toChar = {{0, 'A'}, {1, 'T'}, {2, 'G'}, {3, 'C'}};
//     int bigBase = 512 * 512;
    

//     string getStr(int a) { // int -> string
//         char tmp[10];
//         for(int i = 0; i < 10; i++) {
//             int cur = a % 4;
//             a /= 4;
//             tmp[i] = toChar[cur];
//         }
//         return  string(tmp, tmp+10);
//     }


//     vector<string> findRepeatedDnaSequences(string s) {
//         int n = s.size();
//         vector<string>  res;
//         if(n < 10)
//             return  res;

//         // 使用一个int型的cur记录当前的值，这个值代表了当前的size为10的字串
//         // 用值来代替字符串，比较简单
//         int cur = 0;
//         unordered_map<int, int>    cnt;
//         for(int i = 9; i >= 0; i--) {
//             cur *= 4;
//             cur += m[s[i]];
//         }

//         cnt[cur]++; //录入第一个
//         for(int i = 10; i < n; i++) {
//             // 每次算一个代表size为10的字串对应的编码
//             // 编码方法，从右往左算位数i(范围0到9), cur = sum(4^i * code(ATGC))，其中i为0-9
//             cur /= 4;
//             cur += m[s[i]] * bigBase;
//             if(cnt[cur]++ == 1)
//                 res.push_back(getStr(cur));
//         }
   
//         return  res;
//     }
// };