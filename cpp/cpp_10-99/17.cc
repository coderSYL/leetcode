// C++
// leetcode 17
// url: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// 思路:
// 将ret写在类里，然后写一个dfs的函数，用dfs把答案装进ret里

class Solution {
public:
    vector<string> phone_keyboard{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ret;

    void dfs(string pre, int *num, int done,int size)
    {
        if(size ==done)
        {
            ret.push_back( pre);
            return;
        }
        for(char c: phone_keyboard[ num[done]])
        {
            string temp = pre + c;
            dfs(temp, num, done+1, size);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        int size = digits.size();
        if(size ==0)
            return ret;
        int num[size];
        for(int i =0; i<size; i++)
        {
            num[i] = ((int)digits[i] -50);
        }
        string temp[size];
        dfs("", num, 0, size);
        return ret;
    }
};