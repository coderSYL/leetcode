// Go
// leetcode 1750
// https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/

func minimumLength(s string) int {
    n := len(s)
	start, end := 0, n - 1
	for start < end {
		if s[start] != s[end] {
			break
		}
		c := s[start]
		l, r := start, end
		for l <= r && s[l] == c {
			l++
		}
		for l <= r && s[r] == c {
			r--
		}
		start = l
		end = r
	}
	return end - start + 1
}