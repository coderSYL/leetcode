// Go
// leetcode 1656
// https://leetcode.cn/problems/design-an-ordered-stream/

type OrderedStream struct {
	arr []int
	ptr int
	tmp []byte
}


func Constructor(n int) OrderedStream {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = -1
	}
	return OrderedStream{arr, 0, make([]byte, 5)}
}

func getIdx(s string) int {
	idx := 0
	for i := 0; i < 5; i++ {
		idx = idx * 26 + int(s[i] - 'a')
	}
	return idx
}

func (t *OrderedStream) LoadInTmp(x int) bool {
	if x == -1 {
		return false
	}

	for i := 4; i >= 0; i-- {
		t.tmp[i] = 'a' + byte(x % 26)
		x /= 26
	}

	return true
}

func (t *OrderedStream) Insert(idKey int, value string) []string {
	res := []string{}
	t.arr[idKey - 1] = getIdx(value)
	p := t.ptr
	for p < len(t.arr) {
		if t.LoadInTmp(t.arr[p]) {
			res = append(res, string(t.tmp))
			p++
		} else {
			break
		}
	}
	t.ptr = p
	return res
}


/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */