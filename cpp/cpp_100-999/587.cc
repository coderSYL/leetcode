// C++
// leetcode 587
// https://leetcode-cn.com/problems/erect-the-fence/
// 凸包

class Solution {
public:
    struct Info // template
    {
        int x;
        int y;
        Info(){}
        Info(int x, int y) : x(x), y(y) {}
        void reset(int x_, int y_) {
            x = x_;
            y = y_;
        }
        // 小顶堆的排序： 高度从小到大排列
        bool operator<(const Info& a) const
        {
            if(x != a.x)
                return x < a.x;
            return y < a.y;
        }
    };

    Info sub(Info a, Info b) {
        return Info(a.x - b.x, a.y - b.y);
    }

    int cross(Info a, Info b) {
        return a.x * b.y - a.y * b.x;
    }

    // 向量ab转化为向量ac过程中扫过的面积
    int getArea(Info a, Info b, Info c) {
        return cross(sub(b,a), sub(c,a));
    }


    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<Info> tmp(n);
        for(int i = 0; i < n; i++) {
            tmp[i].reset(trees[i][0], trees[i][1]);
        }
        sort(tmp.begin(), tmp.end());

        int tp = 0; // top
        int stk[n+10];
        bool vis[n+10];
        memset(vis, 0, sizeof(vis));
        stk[++tp] = 0;
        for(int i = 1; i < n; ++i) {
            Info &c = tmp[i];
            while(tp >= 2) {
                Info &a = tmp[stk[tp-1]], &b = tmp[stk[tp]];
                if(getArea(a, b, c) > 0) {
                    vis[stk[tp--]] = false;
                }
                else
                    break;
            }
            stk[++tp] = i;
            vis[i] = true;
        }

        int size = tp;
        for(int i = n-1; i >= 0; --i) {
            if(vis[i])
                continue;
            Info c = tmp[i];
            while(tp > size) {
                Info a = tmp[stk[tp-1]], b = tmp[stk[tp]];
                if(getArea(a, b, c) > 0) {
                    tp--;
                }
                else
                    break;
            }
            stk[++tp] = i;
        }

        vector<vector<int>> res(tp-1, vector<int>(2));
        for(int i = 1; i < tp; ++i) {
            res[i-1][0] = tmp[stk[i]].x;
            res[i-1][1] = tmp[stk[i]].y;
        }
        return res;
    }
};