// Go
// leetcode 2432
// https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/

func hardestWorker(n int, logs [][]int) int {
	res, curTime := 0, 0
	cnt := make([]int, n)
	for i := 0; i < len(logs); i++ {
		workerId := logs[i][0]
		leaveTime := logs[i][1]
		cnt[workerId] = max(cnt[workerId], leaveTime-curTime)
		curTime = leaveTime
		if cnt[workerId] > cnt[res] || (cnt[workerId] == cnt[res] && workerId < res) {
			res = workerId
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}