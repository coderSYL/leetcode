// Go
// leetcode 1616
// https://leetcode.cn/problems/split-two-strings-to-make-palindrome/

func checkPalindromeFormation(a string, b string) bool {
	return helper(a, b) || helper(b, a)
}

func helper(a, b string) bool {
	n := len(a)
	// a center
	l, r := (n-1)/2, n/2
	for l >= 0 && a[l] == a[r]{
		l--
		r++
	}
	for l >= 0 && a[l] == b[n-1-l] {
		l--
	}
	if l == -1 {
		return true
	}
	for r < n && a[r] == b[n-1-r]{
		r++
	}
	if r == n {
		return true
	}
	return false
}