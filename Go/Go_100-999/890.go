// Go
// leetcode 890
// https://leetcode.cn/problems/find-and-replace-pattern/

func findAndReplacePattern(words []string, pattern string) []string {
	m :=  len(pattern)
	var a, b [26]int
	var res []string
	out:
		for _, s := range words {
			if len(s) != m {
				continue
			}
			for i := 0; i < 26; i++ {
				a[i] = -1
				b[i] = -1
			}
			for i := 0; i < m; i++ {
				u1, u2 := int(pattern[i] - 'a'), int(s[i] - 'a')
				if a[u1] == -1 && b[u2] == -1 {
					a[u1] = u2
					b[u2] = u1
				} else if a[u1] == u2 && b[u2] == u1 {
					continue
				} else {
					continue out
				}
			}
			res = append(res, s)
		}
	return res
}