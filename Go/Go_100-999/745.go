// Go
// leetcode 745
// https://leetcode.cn/problems/prefix-and-suffix-search/

type TrieNode struct {
	Tns [26]*TrieNode
	idxs []int
}

func Insert(tr1, tr2 *TrieNode, s string, tag int) {
	n := len(s)
	var u int

	// 把正序 s 插入 tr1 中
	for i := 0; i < n; i++ {
		u = int(s[i] - 'a')
		if tr1.Tns[u] == nil {
			tr1.Tns[u] = &TrieNode{}
		}
		tr1 = tr1.Tns[u]
		tr1.idxs = append(tr1.idxs, tag)
	}

	// 把倒序 s 插入 tr2 中
	for i := n - 1; i >= 0; i-- {
		u = int(s[i] - 'a')
		if tr2.Tns[u] == nil {
			tr2.Tns[u] = &TrieNode{}
		}
		tr2 = tr2.Tns[u]
		tr2.idxs = append(tr2.idxs, tag)
	}
}

func Query(tr1, tr2 *TrieNode, a, b string) int {
	// 在 tr1 里搜索 以 a 为前缀的字符串的编号
	var u int
	for i := 0; i < len(a); i++ {
		u = int(a[i] - 'a')
		if tr1.Tns[u] == nil {
			return -1
		}
		tr1 = tr1.Tns[u]
	}

	// 在 tr2 里搜索 以 b 为前缀的字符串的编号
	for i:= len(b) - 1; i >= 0; i-- {
		u = int(b[i] - 'a')
		if tr2.Tns[u] == nil {
			return -1
		}
		tr2 = tr2.Tns[u]
	}

	// 在两个数组里搜索最大的共同编号
	for i, j := len(tr1.idxs) - 1, len(tr2.idxs) - 1; i >= 0 && j >= 0; {
		if tr1.idxs[i] == tr2.idxs[j] {
			return tr1.idxs[i]
		} else if tr1.idxs[i] > tr2.idxs[j] {
			i--
		} else {
			j--
		}
	}

	return -1
}

type WordFilter struct {
	tr1, tr2 *TrieNode
}


func Constructor(words []string) WordFilter {
	t1, t2 := &TrieNode{}, &TrieNode{}

	for i, s := range words {
		Insert(t1, t2, s, i)
	}
	
	return WordFilter{t1, t2}
}


func (this *WordFilter) F(pref string, suff string) int {
	return Query(this.tr1, this.tr2, pref, suff)
}


/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(pref,suff);
 */