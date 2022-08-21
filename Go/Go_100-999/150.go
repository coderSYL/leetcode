// Go
// leetcode 150
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
// 遇上数字就压栈，遇上符号就提取两个数字然后计算，再压栈

import (
	"strconv"
)

func evalRPN(tokens []string) int {
	stk := make([]int, 0, 4)
    var n int
	for _, s := range tokens {
		if len(s) == 1 && isSymbol(s[0]) {
			n = len(stk)
			switch s[0] {
			case '+':
				stk[n-2] += stk[n-1]
			case '-':
				stk[n-2] -= stk[n-1]
			case '*':
				stk[n-2] *= stk[n-1]
			case '/':
				stk[n-2] /= stk[n-1]
			}
			stk = stk[0 : n-1]
		} else {
			n, _ = strconv.Atoi(s)
			stk = append(stk, n)
		}
	}
	return stk[0]
}

func isSymbol(c byte) bool {
	if c == '+' || c == '-' || c == '*' || c == '/' {
		return true
	}
	return false
}