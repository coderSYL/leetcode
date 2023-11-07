// Go
// leetcode 1233
// https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/

type TrieNode struct {
	Trie       [1_00_009][27]int
	IsEnd      [1_00_009]bool
	Idx        int
	Cur        []byte
	GoodFolder []string
}

func (t *TrieNode) Insert(s string) {
	p := 0
	for _, c := range s {
		u := int(c - 'a')
		if u < 0 {
			u = 26
			if t.IsEnd[p] {
				break
			}
		}
		if t.Trie[p][u] == 0 {
			t.Idx++
			t.Trie[p][u] = t.Idx
		}
		p = t.Trie[p][u]
	}
	t.IsEnd[p] = true
	t.Trie[p][26] = 0
}

func (t *TrieNode) dfs(p int) {
	// fmt.Println(">> ", p , " : ", string(t.Cur))
	if t.IsEnd[p] {
		// fmt.Println("<< Good")
		t.GoodFolder = append(t.GoodFolder, string(t.Cur))
	}

	for i := 0; i < 26; i++ {
		if t.Trie[p][i] != 0 {
			// fmt.Println("jump from ", p , " to ",t.Trie[p][i])
			t.Cur = append(t.Cur, byte('a'+i))
			t.dfs(t.Trie[p][i])
			t.Cur = t.Cur[0 : len(t.Cur)-1]
		}

	}
	if !t.IsEnd[p] && t.Trie[p][26] != 0 {
		// fmt.Println("jump from ", p , " to ",t.Trie[p][26])
		t.Cur = append(t.Cur, '/')
		t.dfs(t.Trie[p][26])
		t.Cur = t.Cur[0 : len(t.Cur)-1]
	}
}

func removeSubfolders(folder []string) []string {
	t := TrieNode{}
	for _, s := range folder {
		t.Insert(s)
	}
	t.dfs(0)
	return t.GoodFolder
}