// Go
// leetcode 1376
// https://leetcode.cn/problems/time-needed-to-inform-all-employees/

func numOfMinutes(n int, headID int, manager []int, informTime []int) (res int) {
	totalTime := make([]int, n)
	var helper func(int) int
	helper = func(u int) int {
		if u == headID { // 经理，不用通知
			return 0
		}

		if totalTime[u] != 0 { // 计算过
			return totalTime[u]
		}

		directLeader := manager[u]
		time := helper(directLeader) + informTime[directLeader]
		totalTime[u] = time

		return time
	}
	for i := 0; i < n; i++ {
		res = max(res, helper(i))
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}