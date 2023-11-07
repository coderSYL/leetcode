// Go
// leetcode 421
// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

func findMaximumXOR(nums []int) (res int) {
	trie := [2750000][2]int{}
	idx := 0
	add := func(x int) {
		p := 0
		for i := 31; i >= 0; i-- {
			u := (x >> i) & 1
			if trie[p][u] == 0 {
				idx++
				trie[p][u] = idx
			}
			p = trie[p][u]
		}
	}

	getVal := func(x int) (res int) {
		p := 0
		for i := 31; i >= 0; i-- {
			a := (x >> i) & 1
			b := 1 - a
			if trie[p][b] != 0 {
				res += 1 << i
				p = trie[p][b]
			} else {
				p = trie[p][a]
			}
		}
		return res
	}

	for _, x := range nums {
		add(x)
		res = max(res, getVal(x))
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}