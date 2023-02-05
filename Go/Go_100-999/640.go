// Go
// leetcode 640
// https://leetcode.cn/problems/solve-the-equation/

import "strconv"

func isNum(b byte) bool {
	if b >= '0' && b <= '9' {
		return true
	}

	return false
}

func solveEquation(s string) string {
	n, xCnt, val := len(s), 0, 0
	afterEqual := false

loop:
	for i, j := 0, 0; i < n; {
		cur := 1

		switch s[i] {
		case '=':
			afterEqual = true
			i++
			continue loop
		case '+':
			i++
		case '-':
			cur = -1
			i++
		}

		// 找到数字部分，并算入cur
		j = i
		for j < n && isNum(s[j]) {
			j++
		}
		if i != j {
			tmp, _ := strconv.Atoi(s[i:j])
			cur *= tmp
		}

		// 结算此项
		if j < n && s[j] == 'x' {
			j++
			if afterEqual {
				xCnt -= cur
			} else {
				xCnt += cur
			}
		} else {
			if afterEqual {
				val += cur
			} else {
				val -= cur
			}
		}

		i = j
	}

	// 零解和无数解
	if xCnt == 0 {
		if val == 0 {
			return "Infinite solutions"
		} else {
			return "No solution"
		}
	}

	return "x=" + strconv.Itoa(val/xCnt)
}