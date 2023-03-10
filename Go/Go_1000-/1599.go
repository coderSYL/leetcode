// Go
// leetcode 1599
// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/

func minOperationsMaxProfit(customers []int, boardingCost int, runningCost int) int {
	if boardingCost*4 <= runningCost { // 怎么转都不能赚
		return -1
	}

	curProfit, curTimes, curCustomer := 0, 0, 0
	maxProfit, idx := 0, -1
	for _, newCustomer := range customers { // 每站游客依次入列
		curCustomer += newCustomer
		boardingNumber := min(curCustomer, 4)
		curProfit += boardingNumber*boardingCost - runningCost
		curTimes++
		curCustomer -= boardingNumber
		if curProfit > maxProfit {
			idx = curTimes
		}
	}

	// 剩余游客是否成团
	fullTimesLeft := curCustomer / 4
	if fullTimesLeft > 0 {
		curProfit += (boardingCost*4 - runningCost) * fullTimesLeft
		curTimes += fullTimesLeft
	}

	// 剩余散客是否能赚
	if (curCustomer%4)*boardingCost-runningCost > 0 {
		curTimes++
		curProfit += boardingCost*(curCustomer%4) - runningCost
	}
	if curProfit > maxProfit {
		idx = curTimes
	}

	return idx
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}