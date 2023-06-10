// Go
// leetcode 1170
// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/

func numSmallerByFrequency(queries []string, words []string) []int {
	cnt := make([]int, 2002)
	for _, s := range words {
		cnt[f(s)]++
	}

	for i:=1999; i >= 0; i-- {
		cnt[i] += cnt[i+1]	// cnt[i] 表示 words 中 f(w) 大于等于 i 的词的个数
	}

	n := len(queries)
	res := make([]int, n)
	for i:=0; i<n; i++ {
		res[i] = cnt[f(queries[i])+1]
	}
	return res
}

func f(s string) int {
	if len(s) <= 1 {
		return len(s)
	}
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for i:=0; i<26;i++ {
		if cnt[i] != 0 {
			return cnt[i]
		}
	}
	return 0	// never
}