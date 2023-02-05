import "math/rand"

// Go
// leetcode 1206
// https://leetcode.cn/problems/design-skiplist/

var level int = 10

type Node struct {
	val int
	ne  []*Node
}

func newNode(v int) *Node {
	return &Node{v, make([]*Node, level)}
}

type Skiplist struct {
	ns []*Node
	he *Node
}

func Constructor() Skiplist {
	return Skiplist{make([]*Node, level), newNode(-1)}
}

func (this *Skiplist) Find(t int) {
	cur := this.he
	for i := level - 1; i >= 0; i-- {
		for cur.ne[i] != nil && cur.ne[i].val < t {
			cur = cur.ne[i]
		}
		this.ns[i] = cur
	}
}

func (this *Skiplist) Search(t int) bool {
	this.Find(t)
	return this.ns[0].ne[0] != nil && this.ns[0].ne[0].val == t
}

func (this *Skiplist) Add(t int) {
	this.Find(t)
	node := newNode(t)

	for i := 0; i < level; i++ {
		node.ne[i] = this.ns[i].ne[i]
		this.ns[i].ne[i] = node
		if rand.Intn(2) == 0 {
			break
		}
	}
}

func (this *Skiplist) Erase(t int) bool {
	this.Find(t)
	node := this.ns[0].ne[0]
	if node == nil || node.val != t {
		return false
	}

	for i := 0; i < level && this.ns[i].ne[i] == node; i++ {
		this.ns[i].ne[i] = this.ns[i].ne[i].ne[i]
	}
	return true
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Search(target);
 * obj.Add(num);
 * param_3 := obj.Erase(num);
 */