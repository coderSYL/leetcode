// Go
// leetcode 2481
// https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/

func numberOfCuts(n int) int {
    switch {
	case n == 1:
		return 0
	case n % 2 == 0:
		return n/2
	default:
		return n
	}

	return -1 // never
}