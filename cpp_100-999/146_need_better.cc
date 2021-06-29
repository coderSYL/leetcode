// C++
// leetcode 146
// https://leetcode-cn.com/problems/lru-cache/
// 思路

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = good.find(key);
        // 不存在
        if(it == good.end())    return -1;
        // 存在
        Node* temp = pointer[key];
        goToTail(temp);
        return good[key];
    }
    
    void put(int key, int value) {
        auto it = good.find(key);
        if(it == good.end())
        {
            // 不存在
            if(size == capacity_)
            {
                // 满了，删一个
                // 从链表表头获取需要删谁
                int keyToBeDeleted = cutHead();
                auto itToBedeleted = good.find(keyToBeDeleted);
                good.erase(itToBedeleted);
                size--;
            }
            // 删了后相当于没满
            Node *temp = nullptr;
            if(head == nullptr)  temp = makeFirst(key);
            else    temp = addTail(key);
            good[key] = value;
            pointer[key] = temp;
            size++;
        }
        else
        {
            // 存在
            // 需要改值，然后在链表里放到最后面
            good[key] = value;
            Node *temp = pointer[key];
            goToTail(temp);
        }
    }
private:
    struct Node{
        int val;
        Node *next;
        Node *before;
        Node(int x) : val(x){}
        Node(int x, Node *be, Node * ne) : val(x), next(ne), before(be) {}
    };
    map<int, int> good;    // k-v
    map<int, Node*> pointer;    // k-v
    int capacity_;
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    // 造第一个
    Node* makeFirst(int v){
        head = new Node(v, nullptr, nullptr);
        tail = head;
        // cout<<"make first >> "<< v<<endl;
        return head;
    }
    // 去头
    int cutHead(){
        Node* temp = head;
        head = head -> next;
        int val = temp -> val;
        delete temp;
        // cout<<"cut head >> "<< val<<endl;
        return val;
    }
    // 加尾
    Node* addTail(int v){
        Node* temp = new Node(v, tail, nullptr);
        tail -> next = temp;
        tail = temp;
        // cout<<"add tail >> "<< v<<endl;
        return temp;
    }
    // 某一个取出来，然后加到尾巴哪里

    void addTailPointer(Node * p){
        tail ->next = p;
        p ->before = tail;
        p ->next = nullptr;
        tail = p;
    }

    void goToTail(Node *p){
        // cout<<"Go to tail >> "<< p->val<<endl;
        if(p == tail)   return;
        if(p == head)
        {
            head = head->next;
            int v = p->val;
            addTailPointer(p);
            return;
        }
        // 非头非尾
        Node *pre = p -> before;
        Node *after = p -> next;
        pre -> next = after;
        after ->before = pre;
        addTailPointer(p);
    }
};

// 我对链表可能的操作：
// 尾部加入
// 中间某一个给它取出来，放到结尾处
// 删除头部

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */