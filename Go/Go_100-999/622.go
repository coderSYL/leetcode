// Go
// leetcode 622
// https://leetcode.cn/problems/design-circular-queue/

type MyCircularQueue struct {
	Start, Next, ArrSize int
	Arr []int
}


func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{0, 0, k + 1, make([]int, k + 1)}
}


func (t *MyCircularQueue) EnQueue(value int) bool {
	if t.IsFull() {
		return false
	}

	t.Arr[t.Next] = value
	t.Next = (t.Next + 1) % t.ArrSize
	return true
}


func (t *MyCircularQueue) DeQueue() bool {
	if t.IsEmpty() {
		return false
	}

	t.Start = (t.Start + 1) % t.ArrSize
	return true
}


func (t *MyCircularQueue) Front() int {
	if t.IsEmpty() {
		return -1
	}

	return t.Arr[t.Start]
}


func (t *MyCircularQueue) Rear() int {
	if t.IsEmpty() {
		return -1
	}

	return t.Arr[(t.Next - 1 + t.ArrSize) % t.ArrSize]
}


func (t *MyCircularQueue) IsEmpty() bool {
	return t.Start == t.Next
}


func (t *MyCircularQueue) IsFull() bool {
	return t.Start == (t.Next + 1) % t.ArrSize
}


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */