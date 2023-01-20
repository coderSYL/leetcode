// C++
// leetcode 2392
// https://leetcode.cn/problems/build-a-matrix-with-conditions/
// 建图两次
// 找到两个拓扑排序的序列
// 填充答案

class Solution {
public:
    // 图，最多装 N 个结点，M 条边
    const static int N = 405, M = 10009;
    int idx = 0;
    int he[N], e[M], ne[M];
    int in[N];
    bool vis[N];

    // 添加有向边 a -> b
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx++;
        in[b]++;
    }

    // 删除所有从结点 x 出发的边
    void cancel(int x) {
        for (int i = he[x]; i != -1; i = ne[i]) {
            int to = e[i];
            in[to]--;
        }
        he[x] = -1;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        memset(he, -1, sizeof(he) / 405 * (k + 3));
        memset(vis, 0, sizeof(vis));

        // 建立行的关系图
        for (auto &p : rowConditions) {
            add(p[0], p[1]);
        }

        // 根据入度进行拓扑排序
        vector<int> aboveBelow(k);
        int p = 0;
        while(p < k) {
            bool filled = false;
            for (int i = 1; i <= k; i++) {
                if (vis[i])
                    continue;
                if (in[i] == 0) {
                    filled = true;
                    vis[i] = true;
                    aboveBelow[p++] = i;
                    cancel(i);
                    break;
                }
            }
            if (!filled)
                break;
        }
        // 如果无法排出长度为 k 的序列，则爬
        if (p != k) {
            return vector<vector<int>>{};
        }

        // 初始化图以及 标记是否访问的 vis 数组
        memset(vis, 0, sizeof(vis));
        idx = 0;

        // 对列进行相同操作
        for (auto &p : colConditions) {
            add(p[0], p[1]);
        }
        vector<int> leftRight(k);
        p = 0;
        while(p < k) {
            bool filled = false;
            for (int i = 1; i <= k; i++) {
                if (vis[i])
                    continue;
                if (in[i] == 0) {
                    filled = true;
                    vis[i] = true;
                    leftRight[p++] = i;
                    cancel(i);
                    break;
                }
            }
            if (!filled)
                break;
        }
        if (p != k) {
            return vector<vector<int>>{};
        }

        // 填充答案
        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            int x = aboveBelow[i];
            for (int j = 0; j < k; j++) {
                if (leftRight[j] == x) {
                    res[i][j] = x;
                    break;
                }
            }
        }
        return res;
    }
};