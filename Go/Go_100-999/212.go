// Go
// leetcode 212
// https://leetcode.cn/problems/word-search-ii/

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
	}
	t.count[p]++
}

func (t *TrieNode) search(s string) bool {
	p := 0
	// fmt.Println("in: ", s)
	for _, c := range s {
		u := int(c - 'a')
		if t.trie[p][u] == 0 {
			// fmt.Println("out: ", s)
			return false
		}
		p = t.trie[p][u]
	}
	return t.count[p] > 0
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

func findWords(board [][]byte, words []string) (res []string) {
	tn = &TrieNode{}
	dirs := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	for _, s := range words {
		tn.insert(s)
	}

	m, n := len(board), len(board[0])
	visited := make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}

	var dfs func(int, int, int, []byte)
	dfs = func(x, y, id int, cur []byte) {
		// 越界判断
		if x < 0 || y < 0 || x >= m || y >= n || len(cur) > 10 || visited[x][y] {
			return
		}
		u := int(board[x][y] - 'a')
		id = tn.trie[id][u]
		if id == 0 {
			return
		}
		cur = append(cur, board[x][y])
		if tn.count[id] != 0 { // 符合，录入res
			res = append(res, string(cur))
			tn.count[id]--
		}
		visited[x][y] = true
		for i := 0; i < 4; i++ {
			nx, ny := x+dirs[i][0], y+dirs[i][1]
			dfs(nx, ny, id, cur)
		}
		visited[x][y] = false
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			dfs(i, j, 0, []byte{})
		}
	}
	return res
}