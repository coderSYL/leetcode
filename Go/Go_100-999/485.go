// Go
// leetcode 485
// https://leetcode.cn/problems/max-consecutive-ones/

func findMaxConsecutiveOnes(nums []int) int {
	cur, res := 0, 0
	for _, v := range nums {
		if v == 1 {
			cur++
			if cur > res {
				res = cur
			}
		} else {
			cur = 0
		}
	}
	return res
}