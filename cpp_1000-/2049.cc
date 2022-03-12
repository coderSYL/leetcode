// C++
// leetcode 2049
// https://leetcode-cn.com/problems/count-nodes-with-the-highest-score/

class Solution {
public:
    vector<int> edge;
    vector<int> nextEdge;
    vector<int> headEdge;
    vector<int> sizeWithRoot;
    int idx = 0;

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        edge.resize(n + 10);
        nextEdge.resize(n + 10);
        headEdge.resize(n + 10, -1);
        sizeWithRoot.resize(n + 10);
        // 用邻接表建图
        for(int i = 1; i < n; i++) {
            add(parents[i], i);
        }
        dfs(0);
        int res = 0;
        long maxScore = 0;

        for(int i = 0; i < n; i++) {
            long cur = 1;
            if(i != 0)
                cur *= n - sizeWithRoot[i];
            for(int x = headEdge[i]; x != -1; x = nextEdge[x]) {
                cur *= sizeWithRoot[edge[x]];
            }

            if(cur > maxScore) {
                res = 1;
                maxScore = cur;
            } else if(cur == maxScore) {
                res++;
            }
        }
        return res;
    }

    void add(int a, int b) {
        edge[idx] = b;
        nextEdge[idx] = headEdge[a];
        headEdge[a] = idx++;
    }

    int dfs(int a) {
        int res = 1;
        for(int son = headEdge[a]; son != -1; son = nextEdge[son]) {
            res += dfs(edge[son]);
        }
        sizeWithRoot[a] = res;
        return res;
    }
};