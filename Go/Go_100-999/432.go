// Go
// leetcode 432
// https://leetcode.cn/problems/all-oone-data-structure/

type Node struct { // 双链结点
	Left, Right *Node
	Cnt         int
	Set         map[string]bool
}

type AllOne struct {
	Head, Tail *Node
	GetNode    map[string]*Node
}

func Constructor() AllOne {
	var h *Node = &Node{nil, nil, -1000, map[string]bool{}}
	var t *Node = &Node{nil, nil, -1000, map[string]bool{}}
	h.Right, t.Left = t, h
	return AllOne{h, t, map[string]*Node{}}
}

func (this *AllOne) Inc(key string) {
	p, ok := this.GetNode[key]
	var targetNode *Node
	if ok { // 存在
		if p.Right.Cnt == p.Cnt+1 { // 右侧刚好是多一位
			targetNode = p.Right
		} else { // 右侧并非多一位
			targetNode = &Node{p, p.Right, p.Cnt + 1, map[string]bool{}}
			p.Right.Left, p.Right = targetNode, targetNode
		}
		delete(p.Set, key)
		Clean(p)
	} else { // 不存在，插入计数器为 1 的 Node
		if this.Head.Right.Cnt == 1 {
			targetNode = this.Head.Right
		} else {
			targetNode = &Node{this.Head, this.Head.Right, 1, map[string]bool{}}
			this.Head.Right.Left, this.Head.Right = targetNode, targetNode
		}
	}

	targetNode.Set[key] = true
	this.GetNode[key] = targetNode
}

func Clean(p *Node) {
	if p.Cnt < 0 {
		return
	}
	if len(p.Set) == 0 {
		p.Left.Right, p.Right.Left = p.Right, p.Left
	}
}

func (this *AllOne) Dec(key string) {
	old, ok := this.GetNode[key]
	if !ok { // never
		return
	}

	newCnt := old.Cnt - 1

	var targetNode *Node
	if newCnt == 0 {
		targetNode = nil
		delete(this.GetNode, key)
	} else if old.Left.Cnt == newCnt {
		targetNode = old.Left
	} else { // didnt exists, create one
		targetNode = &Node{old.Left, old, newCnt, map[string]bool{}}
		old.Left.Right, old.Left = targetNode, targetNode
	}

	delete(old.Set, key)
	Clean(old)

	if targetNode != nil {
		targetNode.Set[key] = true
		this.GetNode[key] = targetNode
	}
}

func (this *AllOne) GetMaxKey() string {
	p := this.Tail.Left
	if p == this.Head {
		return ""
	}
	for key, _ := range p.Set {
		return key
	}
	return "never"
}

func (this *AllOne) GetMinKey() string {
	p := this.Head.Right
	if p == this.Tail {
		return ""
	}
	for key, _ := range p.Set {
		return key
	}
	return "never"
}

/**
 * Your AllOne object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Inc(key);
 * obj.Dec(key);
 * param_3 := obj.GetMaxKey();
 * param_4 := obj.GetMinKey();
 */