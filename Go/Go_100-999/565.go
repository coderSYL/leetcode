// Go
// leetcode 565
// https://leetcode.cn/problems/array-nesting/

func arrayNesting(nums []int) int {
	n, res := len(nums), 0
	for i := 0; i < n; i++ {
		cur, cnt, tmp := i, 0, 0
		for nums[cur] != -1 {
			cnt++
			tmp = cur
			cur = nums[cur]
			nums[tmp] = -1
		}
		if cnt > res {
			res = cnt
		}
	}
	return res
}