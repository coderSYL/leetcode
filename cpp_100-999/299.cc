// C++
// leetcode 299
// https://leetcode-cn.com/problems/bulls-and-cows/
// 


class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        int cnt_secret[10] = {0};
        int cnt_guess[10] = {0};
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i])
                x++;
            cnt_secret[secret[i] - '0']++;
            cnt_guess[guess[i] - '0']++;
        }
        for(int i = 0; i < 10; i++) {
            y += min(cnt_secret[i], cnt_guess[i]);
        }
        return  to_string(x) + "A" + to_string(y - x) + "B";
    }
};