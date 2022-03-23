// C++
// leetcode 517
// https://leetcode-cn.com/problems/super-washing-machines/
// 


class Solution {
public:
    int abs(int a) {
        return  (a > 0 ? a : -a);
    }



    int findMinMoves(vector<int>& machines) {
        int n = machines.size();


        // 计算总衣服数
        int total = 0;
        for(auto x : machines)
            total += x;

        // 不能均分，则不能好了，寄
        if(total % n != 0)
            return  -1;
        int avg = total / n;
        

        int sum_l = 0, sum_r = total;
        int res = 0;
        for(int i = 0; i < n; i++) {
            sum_r -= machines[i];
            int a = max(avg * i - sum_l, 0);
            int b = max((n - i - 1) * avg - sum_r, 0);
            res = max(res, a + b);
            sum_l += machines[i];
        }


        return  res;
    }
};