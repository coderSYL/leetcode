// Go
// leetcode 2413
// https://leetcode.cn/problems/smallest-even-multiple/

func smallestEvenMultiple(n int) int {
	if n&1 == 1 {
		return 2 * n
	}
	return n
}