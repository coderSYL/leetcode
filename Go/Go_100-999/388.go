// Go
// leetcode 388
// https://leetcode.cn/problems/longest-absolute-file-path/

func lengthLongestPath(s string) int {
	n := len(s)
	level, res := 0, 0
	isFile := false
	stk := make([]int, 0, 4)
	for i := 0; i < n;  {
		level, isFile = 0, false
		for i < n && s[i] == '\t' {
			level++
			i++
		}
		j := i
		for j < n && s[j] != '\n' {
			if s[j] == '.' {
				isFile = true
			}
			j++
		}
		stk = stk[0 : level]
		stk = append(stk, j - i)
		if isFile {
			tmp := max(len(stk) - 1, 0)
			for _, v := range stk {
				tmp += v
			}
			res = max(res, tmp)
		}
        i = j+1
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}