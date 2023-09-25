// C++
// leetcode 213
// https://leetcode-cn.com/problems/house-robber-ii/

func rob(nums []int) int {
	n:= len(nums)
	if n == 1 {
		return nums[0]
	}
	head := rob_one(nums[0:n-1])
	tail := rob_one(nums[1:])
	return max(head, tail)
}

func rob_one(nums []int) (res int) { // 198 的题解
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