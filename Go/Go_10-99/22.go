// Go
// leetcode 22
// https://leetcode.cn/problems/generate-parentheses/

func generateParenthesis(n int) []string {
	m := make([](map[string]bool), n+1)
    for i := 0; i <=n; i++ {
        m[i] = make(map[string]bool)
    }
	m[0][""] = true
	m[1]["()"] = true
	for i := 2; i <= n; i++ {
		// (i-1)
		for s, _ := range m[i-1] {
			(m[i])["(" + s + ")"] = true
		}
		// (p)q
		for p := 0; p < i; p++ {
			q := i-1-p
			for s1, _ := range m[p] {
				for s2, _ := range m[q] {
					m[i]["(" + s1 + ")" + s2] = true
				}
			}
		}
	}
	res := make([]string, 0, len(m[n]))
	for s, _ := range m[n] {
		res = append(res, s)
	}
	return res
}