// Go
// leetcode 20
// https://leetcode.cn/problems/valid-parentheses/

func isValid(s string) bool {
	stk := make([]rune, 0, 10)
	for _, r := range s {
		switch r {
		case '[', '(', '{':
			stk = append(stk, r)
		case ']':
			if len(stk) == 0 || stk[len(stk)-1] != '[' {
				return false
			}
			stk = stk[:len(stk)-1]
		case ')':
			if len(stk) == 0 || stk[len(stk)-1] != '(' {
				return false
			}
			stk = stk[:len(stk)-1]
		case '}':
			if len(stk) == 0 || stk[len(stk)-1] != '{' {
				return false
			}
			stk = stk[:len(stk)-1]
		default:
			return false
		}
	}
	return len(stk) == 0
}