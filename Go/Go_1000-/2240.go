// Go
// leetcode 2240
// https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/

func waysToBuyPensPencils(total int, cost1 int, cost2 int) int64 {
	var res int64
	if cost1 < cost2 {
		cost1, cost2 = cost2, cost1
	}

	rest := total
	for rest >= 0 {
		res += int64(rest / cost2) + 1
		rest -= cost1
	}

	return res
}