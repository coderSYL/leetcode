// Go
// leetcode 1638
// https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/

func countSubstrings(s string, t string) (res int) {
	n, m := len(s), len(t)
	for d := 1 - m; d < n; d++ {
		i := max(0, d)
		for pre2, pre1 := i-1, i-1; i < n && i-d < m; i++ {
			if s[i] != t[i-d] {
				pre2, pre1 = pre1, i
			}
			res += pre1 - pre2
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