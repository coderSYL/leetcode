// C++
// leetcode 1656
// https://leetcode.cn/problems/design-an-ordered-stream/

class OrderedStream {
public:
    vector<int> vs;
    int ptr;
    char tmp[5];
    OrderedStream(int n) {
        vs.resize(n, -1);
        ptr = 0;
    }
    
    int getIdx(string &s) {
        int idx = 0, u = -1;
        for (int i = 0; i < 5; i++) {
            u = s[i] - 'a';
            idx = idx * 26 + u;
        }
        return idx;
    }

    bool loadInTmp(int x) {
        if (x == -1)
            return false;

        char c;
        for (int i = 4; i >= 0; i--) {
            c = 'a' + (x % 26);
            tmp[i] = c;
            x /= 26;
        }
        return true;
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        vs[idKey - 1] = getIdx(value);
        int p = ptr;
        while (p < vs.size()) {
            if (loadInTmp(vs[p])) {
                res.push_back(string(tmp, tmp + 5));
                p++;
            } else {
                break;
            }
        }
        ptr = p;
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */