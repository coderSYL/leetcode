// Go
// leetcode 7
// https://leetcode.cn/problems/reverse-integer/

import "math"

func reverse(x int) int {
	var after, before int64
	before = int64(x)
	var isNegative bool
	if before < 0 {
		isNegative = true
		before = -before
	}
	for before > 0 {
		after = after*10 + before%10
		before /= 10
	}
	if isNegative {
		after = -after
	}
	// fmt.Println(after)
	if after >= int64(math.MinInt32) && after <= int64(math.MaxInt32) {
		return int(after)
	}
	return 0
}