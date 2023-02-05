// Go
// leetcode 2390
// https://leetcode.cn/problems/removing-stars-from-a-string/

func removeStars(s string) string {
	n := len(s)
	tmp := make([]byte, n)
	var p int
	for i := 0; i < n; i++ {
		if s[i] == '*' {
			p--
		} else {
			tmp[p] = s[i]
			p++
		}
	}
	return string(tmp[0:p])
}