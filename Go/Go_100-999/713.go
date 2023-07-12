// Go
// leetcode 713
// https://leetcode.cn/problems/subarray-product-less-than-k/

func numSubarrayProductLessThanK(nums []int, k int) int {
	n := len(nums)
	product := 1
	res := 0
	for l, r := 0, 0; l < n; l++ {
		if r < l {
			r = l
		}
		for r < n && product*nums[r] < k {
			product *= nums[r]
			r++
		}
		res += r - l
		if l != r {
			product /= nums[l]
		}
	}
	return res
}