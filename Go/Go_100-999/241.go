// Go
// leetcode 241
// https://leetcode.cn/problems/different-ways-to-add-parentheses/

func diffWaysToCompute(expression string) []int {
	return dfs(expression, 0, len(expression) - 1)
}

func dfs(s string, l, r int) (res []int) {
	for i:= l; i <= r; i++ {

		if s[i] >= '0' && s[i] <= '9' {
			continue
		}

		left := dfs(s, l, i - 1)
		right := dfs(s, i + 1, r)
		for _, x := range left {
			for _, y := range right {
				if s[i] == '+' {
					res = append(res, x+y)
				} else if s[i] == '-' {
					res = append(res, x-y)
				} else {
					res = append(res, x*y)
				}
			}
		}
	}

	if len(res) == 0 {
		tmp := 0
		for i := l; i <= r; i++ {
			tmp = tmp * 10 + int(s[i] - '0')
		}
		return []int{tmp}
	}

	return res
}