// C++
// leetcode 66
// https://leetcode-cn.com/problems/plus-one/
// 


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool p1 = true;
        int n = digits.size();

        // 检测是否全员都是9，如果是则特殊处理
        bool allNine = true;
        for(auto x : digits) {
            if(x != 9) {
                allNine = false;
                break;
            }
        }
        if(allNine) {
            vector<int> resForAllNine(n + 1, 0);
            resForAllNine[0] = 1;
            return  resForAllNine;
        }


        // 进一处理
        for(int i = n - 1; i >= 0; i--) {
            if(p1) {
                digits[i]++;
                if(digits[i] < 10)
                    p1 = false;
                else
                    digits[i] = 0;
            } else {
                break;
            }
        }
        return  digits;
    }
};