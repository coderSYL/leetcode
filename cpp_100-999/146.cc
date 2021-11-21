// C++
// leetcode 146
// https://leetcode-cn.com/problems/lru-cache/
// 新思路参考了宫水三叶的题解

class LRUCache {
private:
    struct Node{
        int k_, v_;
        Node *l_, *r_;
        Node(int k, int v) : k_(k), v_(v), l_(nullptr), r_(nullptr) {}
        Node(int k, int v, Node *l, Node *r) : k_(k), v_(v), l_(l), r_(r) {}
    };

    map<int, Node*> map;    // < k , Node>
    int capacity_;
    Node *head, *tail;

    // delete 操作：
    // 将指针 node 指向的结点，从双向链表中删除
    void deletee(Node* node){
        Node *l = node -> l_;
        if(l == nullptr)
            return;
        Node *r = node -> r_;
        l -> r_ = r;
        r -> l_ = l;
    }

    // refresh 操作，分两步
    // 1. 将 node 从链表中删除
    // 2. 将此结点加入链表头部
    void refresh(Node *node) {
        deletee(node);
        node -> r_ = head -> r_;
        node -> l_ = head;
        node -> r_ ->l_ = node;
        head -> r_ = node;
    }
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1, head, nullptr);
        head -> r_ = tail;
    }
    
    int get(int key) {
        auto x = map.find(key);
        if(x == map.end())
            return  -1;
        refresh(x -> second);
        return  x -> second -> v_;
    }
    
    void put(int key, int value) {
        Node *node = nullptr;
        if(map.find(key) != map.end()) {
            node = map[key];
            node -> v_ = value;
        } else {
            if(map.size() < capacity_) {
                // 够用
                node = new Node(key, value);
                map[key] = node;
            } else {
                // 不够用
                node = tail -> l_;
                map.erase(node -> k_);
                map[key] = node;
                node -> k_ = key;
                node -> v_ = value;
            }
        }
        refresh(node);
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */