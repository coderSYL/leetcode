// Go
// leetcode 2357
// https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/

func minimumOperations(nums []int) int {
	exist := make([]bool, 101)
	for _, x := range nums {
		exist[x] = true
	}

	res := 0
	for i := 1; i <= 100; i++ {
		if exist[i] {
			res++
		}
	}
	return res
}