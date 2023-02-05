// Go
// leetcode 1450
// https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/

func busyStudent(startTime []int, endTime []int, queryTime int) (res int) {
	n := len(startTime)
	for i := 0; i < n; i++ {
		if startTime[i] <= queryTime && queryTime <= endTime[i] {
			res++
		}
	}
	return res
}