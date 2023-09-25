// Go
// leetcode 198
// https://leetcode.cn/problems/house-robber/

func rob(nums []int) (res int) {
	pre := make([]int, 3)
	getMaxPreFrom12 := func() int {
		res := 0
		for i := 1; i < 3; i++ {
			res = max(res, pre[i])
		}
		return res
	}

	updatePre := func(x int) {
		pre[2] = pre[1]
		pre[1] = pre[0]
		pre[0] = x
	}

	for _, x := range nums {
		cur := x + getMaxPreFrom12()
		res = max(res, cur)
		updatePre(cur)
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}