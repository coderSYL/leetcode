// Go
// leetcode 283
// https://leetcode.cn/problems/move-zeroes/

func moveZeroes(nums []int) {
	n := len(nums)
	j := 0
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			continue
		} else {
			nums[j] = nums[i]
			j++
		}
	}
	for j < n {
		nums[j] = 0
		j++
	}
	return
}