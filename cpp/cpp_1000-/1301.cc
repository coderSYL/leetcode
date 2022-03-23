// C++
// leetcode 1301
// https://leetcode-cn.com/problems/number-of-paths-with-max-score/
// 


class Solution {
private:
    int m_, n_; // 两个边界
    int MOD = (int)1e9 + 7;
    

    // 记录路径数量，
    vector<int> f_; 
    void setF(int x, int y, int val) {
        f_[x * n_ + y] = val;
    }
    int getF(int x, int y) {
        return  f_[x * n_ + y];
    }


    // 记录分数，用一围表示二维
    vector<int> score_; 
    void setScore(int x, int y, int val) {
        score_[x * n_ + y] = val;
    }
    int getScore(int x, int y) {
        return  score_[x * n_ + y];
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        m_ = board.size();
        n_ = board[0].size();
        f_ = vector<int>(m_ * n_, 0);
        score_ = vector<int>(m_ * n_, -1);

        // 设置初始点
        setScore(m_ - 1, n_ - 1, 0);
        setF(m_ - 1, n_ - 1, 1);

        // 设置靠近初始点的两条边
        // 底部横边
        int preF = 1, preScore = 0;
        for(int i = n_ - 2; i >= 0; i--) {
            // 到不了上一格，则这一格也到不了
            if(preF == 0) {
                setF(m_ - 1, i, 0);
                continue;
            }

            int thisScore = board[m_ - 1][i] - '0';
            if(thisScore == 'X' - '0') {
                // 此路不通
                setF(m_ - 1, i, 0);
                preF = 0;
                continue;
            }
            if(thisScore == 'E' - '0')
                thisScore = 0;

            preScore += thisScore;
            setF(m_ - 1, i, preF);
            setScore(m_ - 1, i, preScore);
        }

        // 右侧竖边
        preF = 1, preScore = 0;
        for(int i = m_ - 2; i >= 0; i--) {
            // 到不了上一格，则这一格也到不了
            if(preF == 0) {
                setF(i, n_ - 1, 0);
                continue;
            }
            int thisScore = board[i][n_ - 1] - '0';
            if(thisScore == 'X' - '0') {
                // 此路不通
                setF(i, n_ - 1, 0);
                preF = 0;
                continue;
            }
            if(thisScore == 'E' - '0')
                thisScore = 0;
            preScore += thisScore;

            setF(i, n_ - 1, preF);
            setScore(i, n_ - 1, preScore);
        }


        // 中间主体部分的dp
        for(int i = m_ - 2; i >= 0; i--) {
            for(int j = n_ - 2; j >= 0; j--) {
                // 本轮解决 i, j位置的最大分问题，可以从下方，右方，右下方得到

                int thisScore = board[i][j] - '0';  // 此格分数
                // 此路不通
                if(thisScore == 'X' - '0') {
                    setF(i, j, 0);
                    setScore(i, j, -1);
                    
                    continue;
                }
                // 若是终点，把分数设为0
                if(thisScore == 'E' - '0')
                    thisScore = 0;

                int a[2] = {-1, 0}, b[2] = {-1, 0}, c[2] = {-1, 0}; //  < score, num >
                // 下方
                a[0] = getScore(i + 1, j);
                a[1] = getF(i + 1, j);
                // 右方
                b[0] = getScore(i, j + 1);
                b[1] = getF(i, j + 1);
                // 右下方
                c[0] = getScore(i + 1, j + 1);
                c[1] = getF(i + 1, j + 1);
                int *good = a;  // 用good存分数最高的二元组 {score, num}
                if(b[0] == good[0]) {
                    good[1] += b[1];
                    good[1] %= MOD;
                } else if(b[0] > good[0]) {
                    good = b;
                }
                if(c[0] == good[0]) {
                    good[1] += c[1];
                    good[1] %= MOD;
                } else if(c[0] > good[0]) {
                    good = c;
                }
                // 设置值
                setF(i, j, good[1]);
                setScore(i, j, good[0] + thisScore);
            }
        }

        // 分数为负或者数量为0都说明到不了
        if(getScore(0,0) < 0 || getF(0, 0) == 0)
            return  vector<int>{0, 0};
        
        return  vector<int>{getScore(0,0), getF(0,0)};
    }
};