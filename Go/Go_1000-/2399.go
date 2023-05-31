// Go
// leetcode 2399
// https://leetcode.cn/problems/check-distances-between-same-letters/

func checkDistances(s string, distance []int) bool {
	vis := make([]bool, 26)
	n := len(s)
	for i, r := range s {
		u := int(r - 'a')
		if vis[u] {
			continue
		}
		if i+distance[u]+1 >= n || s[i+distance[u]+1] != byte(r) {
			return false
		}
		vis[u] = true
	}
	return true
}