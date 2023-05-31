// Go
// leetcode 1641
// https://leetcode.cn/problems/count-sorted-vowel-strings/

func countVowelStrings(n int) (res int) {
	for kind := 1; kind <= 5; kind++ {
		if n < kind {
			break
		}
		cur := Cab(5, kind) * Cab(n-1, kind-1)
		res += cur
	}
	return res
}

func Cab(a, b int) int { // a 底，b 在上
	if a < b {
		return 0
	}
	b = min(b, a-b)
	up, down := 1, 1
	for b > 0 {
		up *= a
		down *= b
		a--
		b--
	}
	return up / down
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}