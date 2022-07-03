// Go
// leetcode 1456
// https://ssg.leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

func maxVowels(s string, k int) int {
	cur, res, n := 0, 0, len(s)
	for i := 0; i < n; i++ {
		if i >= k && isVowel(s[i-k]) {
			cur--
		}
		if isVowel(s[i]) {
			cur++
			if cur > res {
				res = cur
			}
		}
	}
	return res
}

func isVowel(c byte) bool {
	switch c {
		case 'a', 'e', 'i', 'o', 'u':
			return true
	}
	return false
}