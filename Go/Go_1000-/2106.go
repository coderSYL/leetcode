// Go
// leetcode 2106
// https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/

func maxTotalFruits(fruits [][]int, startPos int, k int) (res int) {
	n := len(fruits)
	for i, j, sum := 0, 0, 0; i < n; i++ {
		for j < n && 2*max(startPos-fruits[i][0], 0)+max(fruits[j][0]-startPos, 0) <= k {
			sum += fruits[j][1]
			j++
		}
		res = max(res, sum)
		sum -= fruits[i][1]
	}
	for i, j, sum := 0, 0, 0; i < n; i++ {
		for j < n && max(startPos-fruits[i][0], 0)+2*max(fruits[j][0]-startPos, 0) <= k {
			sum += fruits[j][1]
			j++
		}
		res = max(res, sum)
		sum -= fruits[i][1]
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}