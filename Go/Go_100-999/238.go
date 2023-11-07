// Go
// leetcode 238
// https://leetcode.cn/problems/product-of-array-except-self/

func productExceptSelf(nums []int) []int {
	n := len(nums)
	cur := 1
	res := make([]int, n)
	for i:=0; i<n; i++ {
		res[i] = cur
		cur *= nums[i]
	}
	cur = 1
	for i:=n-1; i>=0; i-- {
		res[i] *= cur
		cur *= nums[i]
	}
	return res
}