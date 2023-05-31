// Go
// leetcode 146
// https://leetcode.cn/problems/lru-cache/

type Node struct {
	Key, Val    int
	Left, Right *Node
}

type LRUCache struct {
	GetNode    map[int]*Node
	Head, Tail *Node
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
	if ok {
		this.RemoveNode(node)
		this.AddToHead(node)
		// fmt.Println("Get OK",key,node.Val)
		return node.Val
	}
	// fmt.Println("Get --",key)
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	node, exist := this.GetNode[key]
	if exist {
		node.Val = value
		this.RemoveNode(node)
		this.AddToHead(node)
		// fmt.Println("Put CHANGE",key,node.Val)
		return
	}

	if this.Size == this.Cap {
		node = this.Tail.Left // 定位末尾的 Node
		this.RemoveNode(node) // 从链中移除
		// fmt.Println("Put FULL--",key, value, "PRE :", node.Key,node.Val)
		delete(this.GetNode, node.Key)  // 解绑map
		node.Key, node.Val = key, value // 改kv，复用
	} else {
		this.Size++
		node = &Node{
			key, value, nil, nil,
		}
		// fmt.Println("Put NEW---",key, value)
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