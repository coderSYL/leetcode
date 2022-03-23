// C++
// leetcode 815
// https://leetcode-cn.com/problems/bus-routes/
// 参考了三叶的并查集 + 双向 BFS

class Solution {
public:
    // 并查集 数据部分
    int p[100010];
    int find(int x) {
        if(p[x] != x)   p[x] = find(p[x]);
        return p[x];
    }
    void unione(int a, int b) {
        p[find(a)] = p[find(b)];
    }
    bool query(int a, int b) {
        return find(a) == find(b);
    }

    // 
    int start;
    int end;
    vector<vector<int>> rs;
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target ) {
        if(source == target)    return  0;
        routes.swap(rs);
        start = source;
        end = target;
        for(int i = 0; i < 100010; ++i)  p[i] = i;
        for(auto r : rs)
            for(auto x : r) unione(x, r[0]);
        if(!query(source, target))  return -1;
        int res = bfs();
        return res;
    }

    unordered_map<int, set<int> >  map;   // < station , set of routes >

    int bfs() {
        queue<int> q1;
        queue<int> q2;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        int n = rs.size();

        for(int i = 0; i < n; ++i)
        {
            for(auto station : rs[i])
            {
                if(station == start)
                {
                    q1.push(i);
                    m1[i] = 1;
                }
                if(station == end)
                {
                    q2.push(i);
                    m2[i] = 1;
                }
                if(map.find(station) == map.end())
                    map[station] = set<int>{};
                map[station].insert(i);
            }
        }
        for(int i = 0; i < n; ++i)
            if(m1.count(i) && m2.count(i))
                return  1;

        while( !q1.empty() && !q2.empty())
        {
            int res = -1;
            if(q1.size() < q2.size())
                res = update(q1, m1, m2);
            else
                res = update(q2, m2, m1);
            if(res != -1)
                return  res;
        }

        return INT_MAX;
    }

    int update(queue<int> &q, unordered_map<int,int> &cur, unordered_map<int,int> &other) {
        int dealing = q.front();
        int step = cur[dealing];
        q.pop();
        for(auto station : rs[dealing])
        {
            set<int> &tt = map[station];  // 从 station 可以进入的 routes 的集合
            for(auto xx : tt)
            {
                if(cur.find(xx) != cur.end())
                    continue;
                if(other.find(xx) != other.end())
                    return step + other[xx];
                cur[xx] = step + 1;
                q.push(xx);
            }
        }
        return  -1;
    }
};