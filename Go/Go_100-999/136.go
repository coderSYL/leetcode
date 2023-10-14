// Go
// leetcode 136
// https://leetcode.cn/problems/single-number/

func singleNumber(nums []int) int {
	res := 0
	for _, x := range nums {
		res ^= x
	}
	return res
}