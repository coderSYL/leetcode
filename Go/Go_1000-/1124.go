// Go
// leetcode 1124
// https://leetcode.cn/problems/longest-well-performing-interval/

func getPoint(hour int) int {
	if hour > 8 {
		return 1
	} else {
		return -1
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestWPI(hours []int) int {
	n, res := len(hours), 0
	sum := make([]int, n+1)
	for i := 0; i < n; i++ {
		sum[i+1] = sum[i] + getPoint(hours[i])
	}

	for i := n; i > 0; i-- {
		for j := 0; j < i; j++ {
			if sum[i]-sum[j] > 0 {
				res = max(res, i-j)
				break
			}
		}
		if res > i {
			break
		}
	}
	return res
}