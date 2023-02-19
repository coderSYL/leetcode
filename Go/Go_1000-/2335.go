// Go
// leetcode 2335
// https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/

func fillCups(amount []int) int {
	var mx, sum int
	for _, x := range amount {
		sum += x
		if x > mx {
			mx = x
		}
	}

	if mx*2 <= sum {
		return (sum + 1) >> 1
	}

	return mx
}