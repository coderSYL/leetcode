// Go
// leetcode 1993
// https://leetcode.cn/problems/operations-on-tree/

type LockingTree struct {
	owner []int
	sons [][]int
	parent []int
}


func Constructor(parent []int) LockingTree {
	n := len(parent)
	owner := make([]int, n)
	sons := make([][]int, n)
	for i:=1; i<n; i++ {
		sons[parent[i]] = append(sons[parent[i]], i)
	}
	return LockingTree{owner, sons, parent}
}


func (this *LockingTree) Lock(num int, user int) bool {
	if this.owner[num] != 0 { // 已被锁
		return false
	}

	this.owner[num] = user
	return true
}


func (this *LockingTree) Unlock(num int, user int) bool {
	if this.owner[num] != user {
		return false
	}
	this.owner[num] = 0
	return true
}


func (this *LockingTree) Upgrade(num int, user int) bool {
	// 检查祖上是否有锁
	cur := num
	for cur != -1 {
		if this.owner[cur] > 0 {
			return false
		}
		cur = this.parent[cur]
	}


	// 检查是否有上锁子孙
	lockedOffspring := []int{}
	m := len(this.sons[num])
	q := make([]int, m)
	for i, x := range this.sons[num] {
		q[i] = x
	}
	
	for len(q) > 0 {
		x := q[len(q)-1]
		q = q[:len(q)-1]
		if this.owner[x] > 0 {
			lockedOffspring = append(lockedOffspring, x)
		}
		for _, y := range this.sons[x] {
			q = append(q, y)
		}
	}

	if len(lockedOffspring) == 0 { // 无上锁子孙，不行
		return false
	}


	// 符合条件，执行操作
	this.owner[num] = user // lock
	for _, x := range lockedOffspring { // 给子孙解锁
		this.owner[x] = 0
	}
	return true
}


/**
 * Your LockingTree object will be instantiated and called as such:
 * obj := Constructor(parent);
 * param_1 := obj.Lock(num,user);
 * param_2 := obj.Unlock(num,user);
 * param_3 := obj.Upgrade(num,user);
 */