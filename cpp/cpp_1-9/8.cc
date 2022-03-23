/*
 * C++
 * leetcode 8
 * url: https://leetcode-cn.com/problems/string-to-integer-atoi/
 * boring exercise
 */

class Solution {
public:
    long power_10(long i){
        long res = 1;
        while(i>0){
            res*=10;
            i--;
        }
        return res;
    }
    int char2int(char c){
        if(c =='0')
            return 0;
        if(c =='1')
            return 1;
        if(c =='2')
            return 2;
        if(c =='3')
            return 3;
        if(c =='4')
            return 4;
        if(c =='5')
            return 5;
        if(c =='6')
            return 6;
        if(c =='7')
            return 7;
        if(c =='8')
            return 8;
        if(c =='9')
            return 9;
        return 10;  // 出错了

    }
    int myAtoi(string str) {
        int firstNOTspace = 0;
        while(str[firstNOTspace] ==' ')
            firstNOTspace++;    //找到第一个非空格字符
        if(str[firstNOTspace] == '\0')
            return 0;
        bool minus = false;
        if(str[firstNOTspace]== '-'){
            minus = true;
            firstNOTspace++;
        }else if(str[firstNOTspace]== '+')    firstNOTspace++;
        while(str[firstNOTspace]== '0')
            firstNOTspace++;
        int FirstDigit = firstNOTspace;
        // printf("%d-", FirstDigit);
        while(char2int(str[firstNOTspace]) <10)
            firstNOTspace++;
        int LastDigit = firstNOTspace-1;
        // printf("%d", LastDigit);
        if(LastDigit<FirstDigit)
            return 0;
        long res=0;
        if(LastDigit-FirstDigit>= 10){
            if(minus)
                return INT_MIN;
            else
                return INT_MAX;
        }
        for(int i = LastDigit; i>=FirstDigit; i--){
            res += char2int(str[i]) * power_10(LastDigit-i);
        }
        if(minus)
            res *= (-1);
        if(res<= -2147483648)
            return INT_MIN;
        if(res>= 2147483648)
            return INT_MAX;
        return (int)res;
    }
};