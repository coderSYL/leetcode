// Go
// leetcode 636
// https://leetcode.cn/problems/exclusive-time-of-functions/

import (
	"strconv"
)

func exclusiveTime(n int, logs []string) []int {
	res := make([]int, n)
	cur := 0
	stk := make([]int, 0, 4)

	for _, s := range logs {
		p := 0
		for s[p] != ':' {
			p++
		}
		idx, _ := strconv.Atoi(s[0:p])

		p++
		c := s[p]
		for s[p] != ':' {
			p++
		}
		val, _ := strconv.Atoi(s[p+1:])
		// idx c val

		// 入
		sz := len(stk)
		if c == 's' {
			if sz != 0 {
				res[stk[sz-1]] += val - cur
			}
			stk = append(stk, idx)
		} else {
			// 出
			val++
			res[stk[sz-1]] += val - cur
			stk = stk[0 : sz-1]
		}

		cur = val
	}

	return res
}