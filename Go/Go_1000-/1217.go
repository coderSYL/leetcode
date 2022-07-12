// Go
// leetcode 1217
// https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position/

func minCostToMoveChips(position []int) int {
	cnt := 0
	for _, p := range position {
		cnt += p&1
	}
	if len(position) - cnt < cnt {
		return len(position) - cnt
	}
	return cnt
}