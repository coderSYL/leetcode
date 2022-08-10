// C++
// leetcode 1206
// https://leetcode.cn/problems/design-skiplist/

class Skiplist {
public:
    const static int level = 10;
    struct Node {
        int val;
        vector<Node*> ne;
        Node(int v) {
            val = v;
            ne.resize(level);
        }
    };

    vector<Node*> ns;
    Node *he = nullptr;

    Skiplist() {
        he = new Node(-1);
        ns.resize(level);
    }
    
    // 找到每层小于 t 的最大的结点
    void find(int t) {
        auto cur = he;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->ne[i] != nullptr && cur->ne[i]->val < t)
                cur = cur->ne[i];
            ns[i] = cur;
        }
    }

    bool search(int t) {
        find(t);
        return ns[0]->ne[0] != nullptr && ns[0]->ne[0]->val == t;
    }
    
    void add(int t) {
        find(t);
        Node *p = new Node(t);
        for (int i = 0; i < level; i++) {
            p->ne[i] = ns[i]->ne[i];
            ns[i]->ne[i] = p;
            if (rand()%2 == 0) break;
        }
    }
    
    bool erase(int t) {
        find(t);
        Node *p = ns[0]->ne[0];

        if (p == nullptr || p -> val != t)
            return false;

        for (int i = 0; i < level && ns[i] -> ne[i] == p; i++)
            ns[i] -> ne[i] = ns[i] -> ne[i] -> ne[i];
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */