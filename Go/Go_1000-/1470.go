// Go
// leetcode 1470
// https://leetcode.cn/problems/shuffle-the-array/

func shuffle(nums []int, n int) []int {
	res := make([]int, 2 * n)
	for i := 0; i < n; i++ {
		res[2 * i] = nums[i]
		res[2 * i + 1] = nums[n + i]
	}
	return res
}