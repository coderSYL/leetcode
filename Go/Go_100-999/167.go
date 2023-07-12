// Go
// leetcode 167
// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

func twoSum(numbers []int, target int) []int {
	n := len(numbers)
	l, r := 0, n-1
	for l<r {
		sum := numbers[l] + numbers[r]
		if sum == target {
			return []int{l+1, r+1}
		}
		if sum < target {
			l++
		}
		if sum > target {
			r--
		}
	}
	return []int{-1, -1}
}