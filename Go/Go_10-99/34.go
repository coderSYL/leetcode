// Go
// leetcode 34
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

func searchRange(nums []int, target int) []int {
	n := len(nums)
	idx := find(nums, target)
	if idx == n || nums[idx] != target {
		return []int{-1, -1}
	}

	second := find(nums, target+1)-1
	return []int{idx, second}
}

func find(arr []int, x int) int {
	n := len(arr)
	l, r := 0, n-1
	for l <= r {
		mid := l + (r-l)/2
		if arr[mid] < x {
			l = mid+1
		} else {
			r = mid-1
		}
	}
	return l
}