// Go
// leetcode 1155
// https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/

func numRollsToTarget(n int, k int, target int) int { // n 个 k 面骰子
	if n*k < target || n > target {
		return 0
	}

	MOD := 1000_000_007
	dp := make([]int, target+1)
	dp[0] = 1
	finishedRound := 0
	for finishedRound < n {
		finishedRound++
		maxPointForThisTurn := min(target, finishedRound*k)
		for i := maxPointForThisTurn; i >= 0; i-- {
			dp[i] = 0
			for j := 1; j <= k; j++ {
				if i < j {
					break
				}
				dp[i] += dp[i-j]
				dp[i] %= MOD
			}
		}
	}
	return dp[target]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}