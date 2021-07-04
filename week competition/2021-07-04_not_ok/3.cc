// C++
// 周赛 2021-07-04
// 3

class Solution {
public:
    int countGoodNumbers(long long n) {
        long res = 1;
        if(n % 2 == 1) {
            res = 5;
            n--;
        }
        n /=2;
        long temp = 20;
        while(n > 0) {
            if(n % 2 == 1) {
                res = (res * temp) % 1000000007;
                n--;
            } else {
                temp = (temp * temp) % 1000000007;
                n /= 2;
            }
        }
        return (int)res;
    }
};