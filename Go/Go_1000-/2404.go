// Go
// leetcode 2404
// https://leetcode.cn/problems/most-frequent-even-element/

func mostFrequentEven(nums []int) int {
	cnt := make(map[int]int)
	res := -1
	// n := len(nums)
	for _, x := range nums {
		if x%2 == 0 {
			cnt[x]++
			if cnt[x] > cnt[res] || (cnt[x] == cnt[res] && x < res) {
				res = x
			}
		}
	}
	return res
}