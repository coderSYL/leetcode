// Go
// leetcode 2367
// https://leetcode.cn/problems/number-of-arithmetic-triplets/

func arithmeticTriplets(nums []int, diff int) (res int) {
	vis := make([]bool, 201)
	for _, x := range nums {
		if vis[x] {
			continue
		}
		vis[x] = true
		if x-2*diff < 0 {
			continue
		}
		if vis[x-diff] && vis[x-2*diff] {
			res++
		}
	}
	return res
}