// Go
// leetcode 1033
// https://leetcode.cn/problems/moving-stones-until-consecutive/

func numMovesStones(a int, b int, c int) []int {
	a, b, c = makeOrder3(a, b, c)
	res := []int{2, c - a - 2}
	if c-a == 2 {
		res[0] = 0
		return res
	}
	if c-b == 1 || c-b == 2 || b-a == 2 || b-a == 1 {
		res[0] = 1
		return res
	}
	return res
}

func makeOrder3(a, b, c int) (res1, res2, res3 int) {
	if b < a {
		a, b = b, a
	}
	if c < a {
		a, c = c, a
	}
	if c < b {
		b, c = c, b
	}
	return a, b, c
}