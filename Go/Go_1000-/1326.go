// Go
// leetcode 1326
// https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

func minTaps(n int, ranges []int) int {
	start := 0
	tapCnt := 0

	for start < n { // 每轮寻找从 start 用一个水龙头能去到最右的点
		nextPoint := start
		for i, radius := range ranges {
			if i-radius > start {
				continue
			}
			nextPoint = max(nextPoint, i+radius)
		}
		if nextPoint == start { // 不能从 start 往右走了
			return -1
		}
		tapCnt++
		start = nextPoint
	}

	return tapCnt
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}