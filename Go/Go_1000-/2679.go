// Go
// leetcode 2679
// https://leetcode.cn/problems/sum-in-a-matrix/

func matrixSum(nums [][]int) int {
	n := len(nums)
	for i:=0; i<n; i++ {
		sort.Ints(nums[i])
	}

	m:= len(nums[0])
	res := 0
	for j:=m-1; j>=0; j-- {
		cur := 0
		for i :=0; i<n; i++ {
			cur = max(cur, nums[i][j])
		}
		res += cur
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}