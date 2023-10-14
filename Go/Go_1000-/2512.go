// Go
// leetcode 2512
// https://leetcode.cn/problems/reward-top-k-students/

// SmallHeapInt64
import "container/heap"
type SmallHeap []int64
func (h SmallHeap) Len() int { return len(h) }
func (h SmallHeap) Less(i, j int) bool { return h[i] < h[j] } // 小顶堆，返回值决定是否交换元素
func (h SmallHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *SmallHeap) Push(x interface{}) {
	*h = append(*h, x.(int64))
}
func (h *SmallHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func (h *SmallHeap) Top() int64 {
	arr := *h
	return arr[0]
}


func topStudents(positive_feedback []string, negative_feedback []string, report []string, student_id []int, k int) []int {
	n1, n2 := len(positive_feedback), len(negative_feedback)
	locate := 20
	m := (n1+n2)*locate+5
	trie := make([][26]int, m)
	point := make([]int, m)
	idx := 0
	insert := func(s string, score int) {
		p := 0
		for _, c := range s {
			u := int(c-'a')
			if trie[p][u] == 0 {
				idx++
				trie[p][u] = idx
			}
			p = trie[p][u]
		}
		point[p] = score
	}

	getScore := func(s string) int {
		p := 0
		for _, c := range s {
			u := int(c-'a')
			if trie[p][u] == 0 {
				return 0
			}
			p = trie[p][u]
		}
		return point[p]
	}

	for _, s := range positive_feedback {
		insert(s, 3)
	}
	for _, s := range negative_feedback {
		insert(s, -1)
	}

	var h SmallHeap
	for i, sentence := range report {
		id := student_id[i]
		score := 0
		for i:=0; i<len(sentence); {
			j := i
			for j < len(sentence) && sentence[j] != ' ' {
				j++
			}
			score += getScore(sentence[i: j])
			i = j+1
		}

		x := getCode(id, score)
		heap.Push(&h, x)
		for h.Len() > k {
			heap.Pop(&h)
		}
	}

	res := make([]int, k)
	for i:=k-1; i>=0; i-- {
		res[i] = getId(heap.Pop(&h).(int64))
	}
	return res
}

func getCode(id, score int) int64 {
	return int64(score + 300) * 100_000_000_000 + 5_000_000_000 - int64(id)
}

func getId(x int64) int {
	x = x % 100_000_000_000
	x = 5_000_000_000 - x
	return int(x)
}