// Go
// leetcode 153
// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

func findMin(nums []int) int {
	idx := helper(nums, 0, len(nums)-1)
	return nums[idx]
}

func helper(arr []int, l, r int) int {
	// fmt.Println(l, r)
	if l == r {
		return l
	}
	if l+1 == r {
		if arr[l] < arr[r] {
			return l
		} else {
			return r
		}
	}
	if arr[l] < arr[r] {
		return l
	}
	mid := l + (r-l)/2
	if arr[mid] < arr[l] {
		return helper(arr, l, mid)
	}

	return helper(arr, mid, r)
}