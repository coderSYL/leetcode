// C++
// leetcode 470
// https://leetcode-cn.com/problems/implement-rand10-using-rand7/
// 偷评论区的方法，利用1-6来搞一个1/2的概率，然后利用1-5来搞一个1/5的概率，有点牛

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();
        while(a == 7)
            a = rand7();
        while(b > 5)
            b = rand7();
        return  (a&1? 0:5) + b;
    }
};