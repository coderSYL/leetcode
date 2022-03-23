// C++
// leetcode 400
// https://leetcode-cn.com/problems/nth-digit/

//
class Solution {
public:
    // 返回 10 ^ i
    long power_10(long i){
        long res = 1;
        while(i>0){
            res*=10;
            i--;
        }
        return res;
    }

    int findNthDigit(int n) {
        long wei = 1;
        long num = 9;
        while(n - wei * num > 0) {
            n -= wei * num;
            wei++;
            num *= 10;
        }
        
        num /= 9;
        
        long goodNum = num + (n - 1) / wei;
        long position = wei - (n - 1) % wei - 1;	
        goodNum /= power_10(position);
        return  goodNum % 10;
    }
};