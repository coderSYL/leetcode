// Go
// leetcode 5
// https://leetcode.cn/problems/longest-palindromic-substring/

func longestPalindrome(s string) string {
	n := len(s)
	start, end := 0, 0
	for i := 0; i < n; i++ {
		// odd length
		l, r := i, i
		for l >= 0 && r < n && s[l] == s[r] {
			l--
			r++
		}
		if r - l - 1 > end - start {
			start, end = l + 1, r
		}
		// even length
		l, r = i, i + 1
		for l >= 0 && r < n && s[l] == s[r] {
			l--
			r++
		}
		if r - l - 1 > end - start {
			start, end = l + 1, r
		}
	}
	return s[start : end]
}