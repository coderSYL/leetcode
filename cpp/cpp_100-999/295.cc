// C++
// leetcode 295
// https://leetcode-cn.com/problems/find-median-from-data-stream/
// 维护两个优先队列

class MedianFinder {
public:
    /** initialize your data structure here. */
    int size = 0;
    priority_queue<int, vector<int>, greater<int>> r;
    priority_queue<int> l;

    MedianFinder() {
        size = 0;
    }
    
    void adjust() {
        while(l.top() > r.top()) {
            int lt = l.top();
            int rt = r.top();
            l.pop();
            r.pop();
            l.push(rt);
            r.push(lt);
        }
    }

    void addNum(int num) {
        if(size % 2 == 0) {
            l.push(num);
        } else {
            r.push(num);
        }
        size++;
    }
    
    double findMedian() {
        if(size == 1)
            return  (double) l.top();
        adjust();
        double res = l.top();
        if(size % 2 == 0)
            res = (res + r.top()) / 2;
        return  res;
    }
};