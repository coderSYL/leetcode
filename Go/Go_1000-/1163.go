// Go
// leetcode 1163
// https://leetcode.cn/problems/last-substring-in-lexicographical-order/

func lastSubstring(s string) string {
	n := len(s)
	startIndexOfRes := 0
	for i, j := 1, 0; i+j < n; {
		if s[startIndexOfRes+j] == s[i+j] {
			j++
		} else if s[startIndexOfRes+j] > s[i+j] { // 当前res大
			i += j + 1
			j = 0
		} else {
			startIndexOfRes += j + 1
			j = 0
			if startIndexOfRes >= i {
				i = startIndexOfRes + 1
			}
		}
	}
	return s[startIndexOfRes:]
}