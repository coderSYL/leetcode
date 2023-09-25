// Go
// leetcode 146
// https://leetcode.cn/problems/lru-cache/

type Node struct {
	Key, Val    int
	Left, Right *Node
}

type LRUCache struct {
	GetNode    map[int]*Node // key - node
	Head, Tail *Node         // 初始时有两个没有真实意义的站位节点
	Size, Cap  int
}

func (this *LRUCache) RemoveNode(node *Node) {
	// 从原链中切断
	preLeft, preRight := node.Left, node.Right
	preLeft.Right, preRight.Left = preRight, preLeft
}

func (this *LRUCache) AddToHead(node *Node) {
	// 放入链首head
	preHead := this.Head.Right
	this.Head.Right = node
	node.Left, node.Right = this.Head, preHead
	preHead.Left = node
}

func Constructor(capacity int) LRUCache {
	originHead := &Node{}
	originTail := &Node{}
	originHead.Right, originTail.Left = originTail, originHead
	return LRUCache{
		make(map[int]*Node),
		originHead,
		originTail,
		0, capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	node, ok := this.GetNode[key]
	if ok { // 存在
		this.RemoveNode(node) // 从链中去除
		this.AddToHead(node)  // 放到链头处
		return node.Val
	}

	return -1 // 不存在
}

func (this *LRUCache) Put(key int, value int) {
	node, exist := this.GetNode[key]
	if exist { // 已存在，需要改值，挪位置
		node.Val = value
		this.RemoveNode(node)
		this.AddToHead(node)
		return
	}

	if this.Size == this.Cap { // 满了
		node = this.Tail.Left           // 定位末尾的 Node
		this.RemoveNode(node)           // 从链中移除
		delete(this.GetNode, node.Key)  // 解绑map
		node.Key, node.Val = key, value // 改kv，复用
	} else { // 未满
		this.Size++
		node = &Node{
			key, value, nil, nil,
		}
	}

	this.AddToHead(node)
	this.GetNode[key] = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */