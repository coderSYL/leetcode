/*
 * C++
 * leetcode 412
 * url: https://leetcode-cn.com/problems/fizz-buzz/
 * 弄一个 1 到 n的循环
 * 分别判断是否是3，5，15的倍数
 * 然后再往ret中装东西
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        string a("Fizz");
        string b("Buzz");
        string c("FizzBuzz");
        for(int i =1; i<=n; i++){
            if(i%3 == 0){
                if(i%5 ==0)
                    ret.push_back(c);
                else
                    ret.push_back(a);
            }else if( i%5 == 0){
                ret.push_back(b);
            }else{
                ret.push_back(to_string(i));
            }
        }
        a.~string();
        b.~string();
        c.~string();
        return ret;
    }
};