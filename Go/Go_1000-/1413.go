// Go
// leetcode 1413
// https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/

func minStartValue(nums []int) int {
	res, cur := 1000, 0
	for _, x := range nums {
		cur += x
		if cur < res {
			res = cur
		}
	}
	if res > 0 {
		res = 1
	} else {
		res = 1 - res
	}

	return res
}