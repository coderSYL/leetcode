// Go
// leetcode 31
// https://leetcode.cn/problems/next-permutation/

func nextPermutation(nums []int) {
	n := len(nums)
	if n <= 1 {
		return
	}

	i, j, k := n-2, n-1, n-1

	// find nums[i] < nums[j]
	for i >= 0 && nums[i] >= nums[j] {
		i--
		j--
	}

	if i >= 0 { // 不是最后一个排列
		// find nums[i] < nums[k]
		for nums[i] >= nums[k] {
			k--
		}

		// swap
		nums[i], nums[k] = nums[k], nums[i]
	}

	for i, j = j, n-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}