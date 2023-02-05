// Go
// leetcode 641
// https://leetcode.cn/problems/design-circular-deque/

type MyCircularDeque struct {
	arr        []int
	head, end  int
	lastOpIsIn bool
}

func Constructor(k int) MyCircularDeque {
	return MyCircularDeque{make([]int, k), 1, 0, false}
}

func (t *MyCircularDeque) InsertFront(value int) bool {
	if t.IsFull() {
		return false
	}

	t.head = (t.head - 1 + len(t.arr)) % len(t.arr)
	t.arr[t.head] = value
	t.lastOpIsIn = true
	return true
}

func (t *MyCircularDeque) InsertLast(value int) bool {
	if t.IsFull() {
		return false
	}

	t.end = (t.end + 1 + len(t.arr)) % len(t.arr)
	t.arr[t.end] = value
	t.lastOpIsIn = true
	return true
}

func (t *MyCircularDeque) DeleteFront() bool {
	if t.IsEmpty() {
		return false
	}

	t.head = (t.head + 1 + len(t.arr)) % len(t.arr)
	t.lastOpIsIn = false
	return true
}

func (t *MyCircularDeque) DeleteLast() bool {
	if t.IsEmpty() {
		return false
	}

	t.end = (t.end - 1 + len(t.arr)) % len(t.arr)
	t.lastOpIsIn = false
	return true
}

func (t *MyCircularDeque) GetFront() int {
	if t.IsEmpty() {
		return -1
	}
	return t.arr[t.head]
}

func (t *MyCircularDeque) GetRear() int {
	if t.IsEmpty() {
		return -1
	}
	return t.arr[t.end]
}

func (t *MyCircularDeque) IsEmpty() bool {
	if (t.end+1)%len(t.arr) == t.head && !t.lastOpIsIn {
		return true
	}

	return false
}

func (t *MyCircularDeque) IsFull() bool {
	if (t.end+1)%len(t.arr) == t.head && t.lastOpIsIn {
		return true
	}

	return false
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */