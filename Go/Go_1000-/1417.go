// Go
// leetcode 1417
// https://leetcode.cn/problems/reformat-the-string/

func reformat(s string) string {
	n := len(s)

	// 统计字母、数字的个数
	numCnt, letterCnt := 0, 0
	for i := 0; i < n; i++ {
		if isNum(s[i]) {
			numCnt++
		} else {
			letterCnt++
		}
	}

	// 判断是否有解
	if numCnt+1 < letterCnt || letterCnt+1 < numCnt {
		return ""
	}

	numTurn := numCnt >= letterCnt
	num_p, letter_p := 0, 0
	tmp := make([]byte, n)
	for i := 0; i < n; i++ {
		if numTurn {
			for !isNum(s[num_p]) {
				num_p++
			}
			tmp[i] = s[num_p]
			num_p++
		} else {
			for isNum(s[letter_p]) {
				letter_p++
			}
			tmp[i] = s[letter_p]
			letter_p++
		}
		numTurn = !numTurn
	}
	return string(tmp)
}

// 判断某字符是否为数字
func isNum(b byte) bool {
	if b >= '0' && b <= '9' {
		return true
	}
	return false
}