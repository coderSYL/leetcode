// Go
// leetcode 1422
// https://leetcode.cn/problems/maximum-score-after-splitting-a-string/

func maxScore(s string) (res int) {
	n := len(s)
	cur := 0
	for i := 0; i < n - 1; i++ {
		if s[i] == '0' {
			cur++
		}
		res = max(res, 2 * cur + n - i - 1)
	}
	return res - cur - int('1' - s[n - 1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}