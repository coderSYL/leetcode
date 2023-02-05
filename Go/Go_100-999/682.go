// Go
// leetcode 682
// https://leetcode-cn.com/problems/baseball-game/

import (
	"strconv"
)

func calPoints(ops []string) int {
	stk := make([]int, 0, 4)
	tmp := 0
	for _, s := range ops {
		switch s[0] {
		case '+':
			stk = append(stk, stk[len(stk)-1]+stk[len(stk)-2])
		case 'D':
			stk = append(stk, stk[len(stk)-1]*2)
		case 'C':
			stk = stk[0 : len(stk)-1]
		default:
			tmp, _ := strconv.Atoi(s)
			stk = append(stk, tmp)
		}
	}
	tmp = 0
	for _, x := range stk {
		tmp += x
	}
	return tmp
}