// Go
// leetcode 2314
// https://leetcode.cn/problems/maximum-number-of-pairs-in-array/

func numberOfPairs(nums []int) []int {
	cnt := make([]int, 101)
	res := make([]int, 2)
	for _, x := range nums {
		cnt[x]++
	}
	for i := 0; i <= 100; i++ {
		res[0] += cnt[i] >> 1
		res[1] += cnt[i] & 1
	}
	return res
}