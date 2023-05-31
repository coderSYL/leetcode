// Go
// leetcode 1043
// https://leetcode.cn/problems/partition-array-for-maximum-sum/

func maxSumAfterPartitioning(arr []int, k int) int {
	n := len(arr)
	sum := make([]int, n+1)
	for i, x := range arr {
		localMax := x
		size := 1
		for size <= k && i-size+1 >= 0 {
			localMax = max(localMax, arr[i-size+1])
			sum[i+1] = max(sum[i+1], sum[i-size+1]+size*localMax)
			size++
		}
	}
	return sum[n]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}