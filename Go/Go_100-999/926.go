// Go
// leetcode 926
// https://leetcode.cn/problems/flip-string-to-monotone-increasing/

func minFlipsMonoIncr(s string) int {
	n, l, r, res := len(s), 0, 0, 0
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			r--
			res = min(res, l + r)
		} else {
			l++
		}
	}
	res -= r
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}