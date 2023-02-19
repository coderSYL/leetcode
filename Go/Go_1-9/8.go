// Go
// leetcode 8
// https://leetcode.cn/problems/string-to-integer-atoi/

const (
	INT_MIN = -(1 << 31)
	INT_MAX = (1 << 31) - 1
)

func myAtoi(s string) int {
	minus, numOrSymbolAppeared, looping := false, false, true
	var res int64
	for _, c := range s {
		switch c {
		case ' ':
			if numOrSymbolAppeared {
				looping = false
			}
		case '+':
			if numOrSymbolAppeared {
				looping = false
			}
			numOrSymbolAppeared = true
		case '-':
			if numOrSymbolAppeared {
				looping = false
				break
			}
			numOrSymbolAppeared = true
			minus = true
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			res = res*10 + int64(c-'0')
			numOrSymbolAppeared = true
		default:
			looping = false
		}
		if !looping || res > 1<<32 {
			break
		}
	}

	if minus { // 负数
		res = -res
	}
	if res > INT_MAX { // 向上越界
		return INT_MAX
	} else if res < INT_MIN { // 向下越界
		return INT_MIN
	}

	return int(res)
}