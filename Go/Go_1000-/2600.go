// Go
// leetcode 2600
// https://leetcode.cn/problems/k-items-with-the-maximum-sum/

func kItemsWithMaximumSum(numOnes int, numZeros int, numNegOnes int, k int) int {
	take := min(k, numOnes)
	res := take
	k -= take
	if k > 0 {
		take = min(k, numZeros)
		k -= take
	}

	if k > 0 {
		res -= k
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}