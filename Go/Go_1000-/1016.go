// Go
// leetcode 1016
// https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/

func queryString(s string, n int) bool {
	vis := map[int]bool{}
	for i, r := range s {
		x := int(r - '0')
		if x == 0 {
			continue
		}
		for j := i + 1; x <= n; j++ {
			vis[x] = true
			if j == len(s) {
				break
			}
			x = x<<1 | int(s[j]-'0')
		}
	}
	return len(vis) == n
}