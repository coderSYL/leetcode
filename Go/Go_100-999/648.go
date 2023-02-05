// Go
// leetcode 648
// https://leetcode.cn/problems/replace-words/

type TrieNode struct {
	trie  [100009][26]int
	count [100009]int
	idx   int
}

func (t *TrieNode) insert(s string) {
	p := 0
	for _, c := range s {
		u := int(c - 'a')
		if t.trie[p][u] == 0 {
			t.idx++
			t.trie[p][u] = t.idx
		}
		p = t.trie[p][u]
		if t.count[p] > 0 {
			return
		}
	}
	t.count[p]++
}

func (t *TrieNode) searchPre(s string) string {
	p := 0
	// fmt.Println("in: ", s)
	for i, c := range s {
		u := int(c - 'a')
		if t.trie[p][u] == 0 && (i == 0 || t.count[p] == 0) {
			// fmt.Println("out: ", s)
			return s
		}
		if t.count[p] != 0 {
			// fmt.Println("out: ", s[0 : i])
			return s[0:i]
		}

		p = t.trie[p][u]
	}
	// fmt.Println("out: ", s)
	return s
}

func (t *TrieNode) clear() {
	i := t.idx
	for i >= 0 {
		t.count[i] = 0
		for j := 0; j < 26; j++ {
			t.trie[i][j] = 0
		}
		i--
	}
	t.idx = 0
}

var tn *TrieNode

func replaceWords(dictionary []string, sentence string) string {
	// 初始化字典树
	if tn == nil {
		tn = &TrieNode{}
	} else {
		tn.clear()
	}

	// 将前缀录入
	for _, s := range dictionary {
		tn.insert(s)
	}

	n := len(sentence)
	res := ""
	for i := 0; i < n; {
		j := i
		for j < n && sentence[j] != ' ' {
			j++
		}
		res += tn.searchPre(sentence[i:j])
		if j != n {
			res += " "
		}
		i = j + 1
	}
	return res
}
