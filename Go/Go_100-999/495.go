// Go
// leetcode 495
// https://leetcode-cn.com/problems/teemo-attacking/

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func findPoisonedDuration(timeSeries []int, duration int) int {
	res := duration
	for i := len(timeSeries) - 2; i >= 0; i-- {
		res += min(duration, timeSeries[i + 1] - timeSeries[i])
	}
	
    return res
}