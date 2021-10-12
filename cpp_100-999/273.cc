// C++
// leetcode 273
// https://leetcode-cn.com/problems/integer-to-english-words/
//  憨憨题


class Solution {
public:
    string getGe(int ge) {
        switch(ge) {
            case 0 :    return  "";
            case 1 :    return  "One";
            case 2 :    return  "Two";
            case 3 :    return  "Three";
            case 4 :    return  "Four";
            case 5 :    return  "Five";
            case 6 :    return  "Six";
            case 7 :    return  "Seven";
            case 8 :    return  "Eight";
            case 9 :    return  "Nine";
        }
        return  "Error";
    }


    string getStringForLiangWei(int n) {
        if(n < 10)
            return  getGe(n);

        if(n <= 20) {
            switch(n) {
                case 10 : return    "Ten";
                case 11 : return    "Eleven";
                case 12 : return    "Twelve";
                case 13 : return    "Thirteen";
                case 14 : return    "Fourteen";
                case 15 : return    "Fifteen";
                case 16 : return    "Sixteen";
                case 17 : return    "Seventeen";
                case 18 : return    "Eighteen";
                case 19 : return    "Nineteen";
                case 20 : return    "Twenty";
            }
        }

        int shi = n / 10;
        n %= 10;
        string strShi;
        switch(shi) {
            case 2 : strShi = "Twenty";
                break;
            case 3 : strShi = "Thirty";
                break;
            case 4 : strShi = "Forty";
                break;
            case 5 : strShi = "Fifty";
                break;
            case 6 : strShi = "Sixty";
                break;
            case 7 : strShi = "Seventy";
                break;
            case 8 : strShi = "Eighty";
                break;
            case 9 : strShi = "Ninety";
                break;
        }
        return  strShi + (n > 0 ? " " : "") + getGe(n);
    }


        // 针对小于一千的数字
    string getString(int n) {
        int hundred = n / 100;
        n %= 100;
        string res = "";
        if(hundred > 0)
            res = getGe(hundred) + " Hundred";
        
        if(n > 0)
            res = res + (res.size() == 0 ? "" : " ") + getStringForLiangWei(n);
        return  res;
    }



    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        int bi = num / 1000000000;
        num %= 1000000000;
        int mi = num / 1000000;
        num %= 1000000;
        int th = num / 1000;
        num %= 1000;
        string res = "";

        if(bi > 0) {
            // cout<<"have billon"<<endl;
            res = getString(bi) + " Billion";
        }
        if(mi > 0) {
            // cout<<"have millon"<<endl;
            res = res + (res.size() == 0 ?  "" : " ") + getString(mi) + " Million";
        }
        if(th > 0) {
            // cout<<"have thousand"<<endl;
            res = res + (res.size() == 0 ?  "" : " ") + getString(th) + " Thousand";
        }
         if(num > 0) {
            // cout<<"have rest"<<endl;
            res = res + (res.size() == 0 ?  "" : " ") + getString(num);
         }
         return res;
    }
};