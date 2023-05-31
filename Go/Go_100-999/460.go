// Go
// leetcode 460
// https://leetcode.cn/problems/lfu-cache/

import "container/heap"

type LFUCache struct {
	h         *NodeHeap
	Nmap      map[int]*Node
	size, cap int
	opcnt     int
}

type Node struct {
	frequence, lastop int
	key, value        int
	index             int
}
type NodeHeap []*Node

func (h NodeHeap) Len() int { return len(h) }
func (h NodeHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].index, h[j].index = h[j].index, h[i].index
}
func (h NodeHeap) Less(i, j int) bool {
	if h[i].frequence < h[j].frequence {
		return true
	} else if h[i].frequence > h[j].frequence {
		return false
	} else {
		return h[i].lastop < h[j].lastop
	}
}
func (h *NodeHeap) Push(x interface{}) {
	*h = append(*h, x.(*Node))
}
func (h *NodeHeap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return ret
}

func Constructor(capacity int) LFUCache {
	cache := LFUCache{&NodeHeap{}, map[int]*Node{}, 0, capacity, 0}
	heap.Init(cache.h)
	return cache
}

func (this *LFUCache) Get(key int) int {
	if this.cap == 0 {
		return -1
	}
	node, ok := this.Nmap[key]
	if !ok {
		return -1
	} else {
		ret := node.value
		node.frequence++
		node.lastop = this.opcnt
		this.opcnt++
		heap.Fix(this.h, node.index)
		return ret
	}
}

func (this *LFUCache) Put(key int, value int) {
	if this.cap == 0 {
		return
	}
	node, ok := this.Nmap[key]
	if ok {
		node.frequence++
		node.lastop = this.opcnt
		this.opcnt++
		node.value = value
		heap.Fix(this.h, node.index)
	} else {
		if this.size == this.cap {
			unluckyOne := heap.Pop(this.h)
			delete(this.Nmap, unluckyOne.(*Node).key)
		} else {
			this.size++
		}
		newNode := &Node{1, this.opcnt, key, value, this.h.Len()}
		this.opcnt++
		heap.Push(this.h, newNode)
		this.Nmap[key] = newNode
	}
}  