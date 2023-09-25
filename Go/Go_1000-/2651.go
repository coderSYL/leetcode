// Go
// leetcode 2651
// https://leetcode.cn/problems/calculate-delayed-arrival-time/

func findDelayedArrivalTime(arrivalTime int, delayedTime int) int {
	return (arrivalTime + delayedTime) % 24
}