// C++
// leetcode 233
// https://leetcode-cn.com/problems/number-of-digit-one/
// 

class Solution {
public:
    int countDigitOne(int n) {
        long res = 0, i = 1, num = n; 
        while(num) {
            if(num%10 == 0) res += (num/10)*i; //个
            if(num%10 == 1) res += (num/10)*i+(n%i)+1; //十
            if(num%10 > 1) res += ceil(num/10.0)*i;
            num /= 10;
            i *= 10;
        }
        return res;
    }
};