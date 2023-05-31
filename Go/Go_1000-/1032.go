// Go
// leetcode 1032
// https://leetcode.cn/problems/stream-of-characters/
// 要点在于倒序

type StreamChecker struct {
	Trie  [][26]int
	Bs    []byte
	Count []bool
	Idx   int
}

func Constructor(words []string) StreamChecker {
	SC := StreamChecker{Trie: make([][26]int, 500_000),
		Bs:    []byte{},
		Count: make([]bool, 500_000),
		Idx:   0}
	for _, s := range words {
		// Insert s
		p := 0
		for i := len(s) - 1; i >= 0; i-- { // 倒序进入字典树
			u := s[i] - 'a'
			if SC.Trie[p][u] == 0 {
				SC.Idx++
				SC.Trie[p][u] = SC.Idx
			}
			p = SC.Trie[p][u]
		}
		SC.Count[p] = true
	}

	return SC
}

func (this *StreamChecker) Query(letter byte) bool {
	this.Bs = append(this.Bs, letter)
	bs := this.Bs
	p := 0
	for i := len(bs) - 1; i >= 0; i-- { // 倒序查询
		u := bs[i] - 'a'
		if this.Trie[p][u] == 0 {
			return false
		}
		p = this.Trie[p][u]
		if this.Count[p] {
			return true
		}
	}
	return false
}
