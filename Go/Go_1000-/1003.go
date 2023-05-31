// Go
// leetcode 1003
// https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/

func isValid(s string) bool {
	stk := make([]byte, 0)
	for _, r := range s {
		switch r {
		case 'a':
			stk = append(stk, 'a')
		case 'b':
			if len(stk) == 0 || stk[len(stk)-1] != 'a' {
				return false
			}
			stk = append(stk, 'b')
		case 'c':
			if len(stk) == 0 || stk[len(stk)-1] != 'b' {
				return false
			}
			stk = stk[:len(stk)-2]
		}
	}

	return len(stk) == 0
}