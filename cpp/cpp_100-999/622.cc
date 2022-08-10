// C++
// leetcode 622
// https://leetcode.cn/problems/design-circular-queue/

class MyCircularQueue {
public:
	int start, next, arrSize;
	vector<int> arr;
    MyCircularQueue(int k_) {
    	arrSize = k_ + 1;
    	arr.resize(arrSize);
    	start = 0;
    	next = 0;
    }
    
    bool enQueue(int value) {
    	if (isFull())
    		return false;
    	arr[next++] = value;
    	next %= arrSize;
        return true;
    }
    
    bool deQueue() {
    	if (isEmpty())
    		return false;
    	start = (start + 1) % arrSize;
    	return true;
    }
    
    int Front() {
    	if (isEmpty())
    		return -1;
    	return arr[start];
    }
    
    int Rear() {
    	if (isEmpty())
    		return -1;
    	return arr[(next + arrSize -1) % arrSize];
    }
    
    bool isEmpty() {
    	return start == next;
    }
    
    bool isFull() {
    	return (next + 1) % arrSize == start;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */