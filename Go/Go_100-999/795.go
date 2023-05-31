// Go
// leetcode 795
// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

func numSubarrayBoundedMax(nums []int, left int, right int) int {
	var f func(int) int
	f = func(upperBoundary int) int {
		cnt, t := 0, 0
		for _, x := range nums {
			if x > upperBoundary {
				t = 0
			} else {
				t = t + 1
			}
			cnt += t
		}
		return cnt
	}
	return f(right) - f(left-1)
}