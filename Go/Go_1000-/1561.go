import "sort"

// Go
// leetcode 1561
// https://ssg.leetcode.cn/problems/maximum-number-of-coins-you-can-get/

func maxCoins(piles []int) int {
	sort.Ints(piles)
	n := len(piles)
	turn, res, p := n/3, 0, n-2
	for i := 0; i < turn; i++ {
		res += piles[p]
		p -= 2
	}
	return res
}