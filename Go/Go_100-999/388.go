// Go
// leetcode 388
// https://leetcode.cn/problems/longest-absolute-file-path/

func lengthLongestPath(s string) (res int) {
	n := len(s)
	var level int
	isFile := false
	stk := make([]int, 0, 4)
	for i := 0; i < n; {
		level, isFile = 0, false

		for i < n && s[i] == '\t' { // 每个 \t 多加一个层级
			level++
			i++
		}

		j := i
		for j < n && s[j] != '\n' {
			if s[j] == '.' { // . 判断文件
				isFile = true
			}
			j++
		}

		stk = stk[0:level]
		stk = append(stk, j-i)

		if isFile { // 是文件则可以刷一次 res
			tmp := max(len(stk)-1, 0) // slash数量
			for _, v := range stk {
				tmp += v
			}
			res = max(res, tmp)
		}
		i = j + 1
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}