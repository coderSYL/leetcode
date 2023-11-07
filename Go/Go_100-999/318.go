// Go
// leetcode 318
// https://leetcode.cn/problems/maximum-product-of-word-lengths/

func maxProduct(words []string) (res int) {
	cnt := make(map[int]int)
	full := 1<<26 - 1
	for _, s := range words {
		hashForThisWord := 0
		for _, c := range s {
			hashForThisWord |= 1<< (c-'a')
		}
		if hashForThisWord == full || hashForThisWord == 0 {
			continue
		}
		cnt[hashForThisWord] = max(cnt[hashForThisWord], len(s))
		for hash, length := range cnt {
			if hash & hashForThisWord != 0 {
				continue
			}
			res = max(res, length * len(s))
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}