// Go
// leetcode 2409
// https://leetcode.cn/problems/count-days-spent-together/

func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
	arriveDay := max(getDayNumber(arriveAlice), getDayNumber(arriveBob))
	leaveDay := min(getDayNumber(leaveAlice), getDayNumber(leaveBob))
	return max(0, leaveDay-arriveDay+1)
}

func getDayNumber(s string) (dayRankInAYear int) {
	dayForMonth := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	month := int(s[0]-'0')*10 + int(s[1]-'0')
	dayRankInAYear = int(s[3]-'0')*10 + int(s[4]-'0')
	for i := 0; i < month-1; i++ {
		dayRankInAYear += dayForMonth[i]
	}
	return dayRankInAYear
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}