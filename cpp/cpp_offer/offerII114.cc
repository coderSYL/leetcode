// C++
// leetcode offer II 114 同本站269
// https://leetcode.cn/problems/Jf1JuT/

class Solution {
public:
    const static int N = 26, M = 26*26;
    int idx = 0, cnt = 0;
    int he[N], e[M], ne[M];
    int in[N], out[N];
    bool vis[N];
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx++;
        out[a]++;
        in[b]++;
    }

    bool build(string &a, string & b) {
        int n1 = a.size(), n2 = b.size(), diff = 0, len = min(n1, n2);
        while(diff < len) {
            int p1 = a[diff] - 'a', p2 = b[diff] - 'a';
            if(p1 != p2) {
                add(p1, p2);
                return true;
            }
            diff++;
        }
        return n1 <= n2;
    }

    string alienOrder(vector<string>& words) {
        memset(he, -1, sizeof(he));
        int n = words.size();
        for(int i = 0; i < n; i++) {
            for(auto c : words[i]) {
                if(!vis[c - 'a'] && ++cnt)
                    vis[c - 'a'] = true;
            }
            for(int j = 0; j < i; ++j) {
                if(!build(words[j], words[i]))
                    return "";
            }
        }
        // cout<<"pre done"<<endl;
        queue<int> q;
        for(int i = 0; i < 26; ++i) {
            if(vis[i] && in[i] == 0)
                q.push(i);
        }
        // cout<<"first round done"<<endl;
        string res = "";
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            res += (char)(cur + 'a');
            for(int i = he[cur]; i != -1; i = ne[i]) {
                int j = e[i];
                if(--in[j] == 0)
                    q.push(j);
            }
        }
        // cout<<"all done"<<endl;
        return (res.size() == cnt ? res : "");
    }
};