// Go
// leetcode 1464
// https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/

func maxProduct(nums []int) int {
	// arr[0] 记录一位的最大值
	// arr[1] 记录两位的最大值
	arr := make([]int, 2)
	for _, x := range nums {
		// 刷新 arr[1]
		arr[1] = max(arr[1], arr[0]*(x-1))
		// 刷新 arr[0]
		arr[0] = max(arr[0], x-1)
	}
	return arr[1]
}

// 返回最大值
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}