// C++
// leetcode 2024
// https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int res = 0;
        int cnt_t = 0;
        int cnt_f = 0;
        for(int i = 0, j = 0; j < n; j++) {
            if(answerKey[j] == 'T')
                cnt_t++;
            else
                cnt_f++;
            while(cnt_f > k && cnt_t > k) {
                if(answerKey[i] == 'T')
                    cnt_t--;
                else
                    cnt_f--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return  res;
    }
};