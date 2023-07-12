// Go
// leetcode 162
// https://leetcode.cn/problems/find-peak-element/

func findPeakElement(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}
	
	if nums[0] > nums[1] {
		return 0
	}

	if nums[n-1] > nums[n-2] {
		return n-1
	}

	l, r := 0, len(nums)-1
	for l < r {
		mid := l + (r-l)/2
		if nums[mid] < nums[mid+1] {
			l = mid + 1
		} else { // nums[mid] > nums[mid+1]
			r = mid
		}
	}
	return l
}