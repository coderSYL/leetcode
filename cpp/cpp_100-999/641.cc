// C++
// leetcode 641
// https://leetcode.cn/problems/design-circular-deque/

class MyCircularDeque {
public:
    int head, end;
    vector<int> arr;
    bool lastOpIsIn = false;
    MyCircularDeque(int k) {
        arr.resize(k);
        head = 1;
        end = 0;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;

        head = (head - 1 + arr.size()) % arr.size();
        arr[head] = value;
        lastOpIsIn = true;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;

        end = (end + 1 + arr.size()) % arr.size();
        arr[end] = value;
        lastOpIsIn = true;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        lastOpIsIn = false;
        head = (head + 1 + arr.size()) % arr.size();
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        lastOpIsIn = false;
        end = (end - 1 + arr.size()) % arr.size();
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return arr[head];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return arr[end];
    }
    
    bool isEmpty() {
        if ((end + 1) % arr.size() == head && !lastOpIsIn)
            return true;
        return false;
    }
    
    bool isFull() {
        if ((end + 1) % arr.size() == head && lastOpIsIn)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */