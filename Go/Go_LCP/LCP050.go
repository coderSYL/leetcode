// Go
// leetcode LCP50
// https://leetcode.cn/problems/WHnhjV/

func giveGem(gem []int, operations [][]int) int {
	for _, op := range operations {
		giver, taker := op[0], op[1]
		amount := gem[giver] / 2
		gem[giver] -= amount
		gem[taker] += amount
	}
	mx, mn := gem[0], gem[0]
	for _, x := range gem {
		mx = max(mx, x)
		mn = min(mn, x)
	}
	return mx - mn
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}