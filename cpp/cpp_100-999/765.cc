// C++
// leetcode 765
// https://leetcode-cn.com/problems/couples-holding-hands/
// 贪心，每两个座位处理一次，从头处理到尾

// 方法一
// T O(n^2)
// S O(1)
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int res = 0;
        int i = 0;
        while(i < n) {
            int first = row[i];
            int goodSecond;
            if(first % 2 == 0)
                goodSecond = first + 1;
            else
                goodSecond = first - 1;
            if(row[i + 1] == goodSecond) {
                i += 2;
                continue;
            }
            int j = i + 2;
            for(; j < n; ++j) {
                if(row[j] == goodSecond)
                    break;
            }
            swap(row[i + 1], row[j]);
            ++res;
            i += 2;
        }
        return res;
    }
};


// 方法二
// T O(n)
// S O(n)
// class Solution {
// public:
//     int minSwapsCouples(vector<int>& row) {
//         int n = row.size();
//         int findIndex[n];
//         for(int i = 0; i < n; ++i) {
//             findIndex[ row[i] ] = i;
//         }
//         int res = 0;
//         int i = 0;
//         while(i < n) {
//             int first = row[i];
//             int goodSecond;
//             int realSecond = row[i + 1];
//             if(first % 2 == 0)
//                 goodSecond = first + 1;
//             else
//                 goodSecond = first - 1;
//             if(realSecond == goodSecond) {
//                 i += 2;
//                 continue;
//             }
//             int goodIndex = findIndex[goodSecond];
//             swap(findIndex[realSecond], findIndex[goodSecond]);
//             swap(row[i + 1], row[goodIndex]);
//             ++res;
//             i += 2;
//         }
//         return res;
//     }
// };