// C++
// leetcode 43
// https://leetcode-cn.com/problems/multiply-strings/
// 略蛋疼的手法，慢慢搞

class Solution {
public:
    int char2int(char a) {
        return (int)(a - 48);
    }

    char int2char(int a) {
        return (char)(a + 48);
    }

    string multiply(string num1, string num2) {
        int num[220] = {0}; // 用来表示每位的数字，因为两个字符串都是小于110位
        if(num1 == "0" || num2 == "0")
            return "0";
        int size1 = num1.size();
        int size2 = num2.size();
        for(int i = 0; i < size1; ++i) {
            int thisTurn = char2int(num1[size1 - 1 -i]);
            for(int j = 0; j < size2; ++j) {
                num[i + j] += thisTurn * char2int(num2[size2 - 1 - j]);
            }
        }
        for(int i = 0; i < 220; ++i) {
            if(num[i] > 9) {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        int length = 0;
        for(length = 220; length > 0; --length) {
            if(num[length - 1] != 0)
                break;
        }

        char res[length + 1];
        res[length] = '\0';
        for(int i = 0; i < length; ++i) {
            res[i] = int2char(num[length - 1 - i]);
        } 

        return res;
    }
};