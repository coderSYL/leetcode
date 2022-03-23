// C++
// leetcode 212
// https://leetcode-cn.com/problems/word-search-ii/
// trie + dfs + 剪枝


class Solution {
private:
    vector<string>  res;
    int trie[100010][26] = {0};
    int count[100010] = {0};
    int index = 0;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};   // 四个方向
    int m, n;
    void insert(string s) {
        int p = 0;
        for(int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a';
            if(trie[p][u] == 0)
                trie[p][u] = ++index;
            p = trie[p][u];
        }
        count[p]++;
    }

    bool search(string s) {
        int p = 0;
        for(int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a';
            if(trie[p][u] == 0)
                return  false;
            p = trie[p][u];
        }
        return  count[p] != 0;
    }

    void dfs(vector<vector<bool>>& vis, vector<vector<char>>& board, int i, int j, string cur, int id) {
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || cur.size() >= 10)
            return;
        char c = board[i][j];
        int u = c - 'a';
        id = trie[id][u];
        if(id == 0)
            return;
        if(count[id] != 0) {
            res.push_back(cur + c);
            count[id]--;
        }
        vis[i][j] = true;
        for(auto d : dirs) {
            int x = i + d[0];
            int y = j + d[1];
            dfs(vis, board, x, y, cur + c, id);
        }
        vis[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>>  visited(m, vector<bool>(n, false));
        for(auto word : words)
            insert(word);   // 建字典树

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(visited, board, i, j, "", 0);
            }
        }
        return res;
    }
};