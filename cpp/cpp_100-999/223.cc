// C++
// leetcode 223
// https://leetcode-cn.com/problems/rectangle-area/
// 有点憨的题目，讨论就完事了

class Solution {
public:
    int abs(int a) {
        return  (a > 0 ? a : -a);
    }


    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int s2 = abs(bx1 - bx2) * abs(by1 - by2);


        // 算共同的x的长度
        int x = 0;
        if(ax1 <= bx2 && ax1 >= bx1) {
            // ax1在另一个长方形的横边之间
            if((ax2 - ax1) * (bx1 - ax1) > 0)
                x = min(abs(ax1 - ax2), abs(ax1 - bx1));
            if((ax2 - ax1) * (bx2 - ax1) > 0)
                x = min(abs(ax1 - ax2), abs(ax1 - bx2));
        }
        if(ax2 <= bx2 && ax2 >= bx1) {
            if((ax1 - ax2) * (bx1 - ax2) > 0)
                x = min(abs(ax1 - ax2), abs(ax2 - bx1));
            if((ax1 - ax2) * (bx2 - ax2) > 0)
                x = min(abs(ax1 - ax2), abs(ax2 - bx2));
        }
        if(bx2 <= ax2 && bx1 >= ax1)
            x = bx2 - bx1;



        int y = 0;
        if(x != 0 && ay1 <= by2 && ay1 >= by1) {
            if((ay2 - ay1) * (by1 - ay1) > 0)
                y = min(abs(ay1 - ay2), abs(ay1 - by1));
            if((ay2 - ay1) * (by2 - ay1) > 0)
                y = min(abs(ay1 - ay2), abs(ay1 - by2));
        }
        if(x != 0 && ay2 <= by2 && ay2 >= by1) {
            if((ay1 - ay2) * (by1 - ay2) > 0)
                y = min(abs(ay1 - ay2), abs(ay2 - by1));
            if((ay1 - ay2) * (by2 - ay2) > 0)
                y = min(abs(ay1 - ay2), abs(ay2 - by2));
        }
        if(by2 <= ay2 && by1 >= ay1)
            y = by2 - by1;
        // cout<<"s1 : "<<s1<<endl;
        // cout<<"s2 : "<<s2<<endl;
        // cout<<"y : "<<y<<endl;
        // cout<<"x : "<<x<<endl;
        return  s1 + s2 - x * y;
    }
};