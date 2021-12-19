// C++
// leetcode 5937
// https://leetcode-cn.com/problems/sequentially-ordinal-rank-tracker/

class SORTracker {
public:
    struct Node
    {
        string name;
        int score;
        Node(string name, int score) : name(name), score(score) {}
        bool operator<(const Node& a) const {
            return (score == a.score ? name < a.name : score > a.score);
        }
    };
    set<Node> s;
    set<Node>::iterator it = s.begin();

    SORTracker() {
    }
    
    void add(string name, int score) {
        Node cur{name, score};
        s.insert(cur);
        if (it == s.end() || cur < *it) it = prev(it);
    }
    
    string get() {
        return (it++) -> name;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */