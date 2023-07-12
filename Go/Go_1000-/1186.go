// Go
// leetcode 1186
// https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/

func maximumSum(arr []int) int {
	n := len(arr)
	dp := make([]int, 2)
	res := arr[0]
	for i:=0; i<n; i++ {
		dp[1] = max(dp[1] + arr[i], dp[0])
		if dp[0] > 0 {
			dp[0] = dp[0] + arr[i]
		} else {
			dp[0] = arr[i]
		}
		res = max(dp[0], res)
        if i!= 0 {
            res = max(dp[1], res)
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