// Go
// leetcode 522
// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

func findLUSlength(strs []string) int {
	n, res := len(strs), -1
outer:
	for i := 0; i < n; i++ {
		if len(strs[i]) <= res {
			continue
		}
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if check(strs[i], strs[j]) {
				continue outer
			}
		}
		res = len(strs[i])
	}
	return res
}


// check if string s1 is subsequence of string s2
func check(s1, s2 string) bool {
	n1, n2 := len(s1), len(s2)
	if n2 < n1 {
		return false
	}
	f := make([][]int, n1+1)
	for i := range f {
		f[i] = make([]int, n2+1)
	}
	i := 0
	for j := 0; i < n1 && j < n2; j++ {
		if s1[i] == s2[j] {
			i++
		}
	}
	return i == n1
}