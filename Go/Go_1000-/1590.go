// Go
// leetcode 1590
// https://leetcode.cn/problems/make-sum-divisible-by-p/

func minSubarray(nums []int, p int) int {
	n := len(nums)
	maxIdx := make(map[int]int)
	maxIdx[0] = -1
	target := 0
	for _, v := range nums {
		target = (target + v) % p
	}
	if target == 0 {
		return 0
	}
	cur := 0
	res := n
	for i, v := range nums {
		cur = (cur + v) % p
		need := (cur - target + p) % p
		idx, ok := maxIdx[need]
		if ok {
			res = min(res, i-idx)
		}
		maxIdx[cur] = i
	}
	if res == n {
		return -1
	}
	return res
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}