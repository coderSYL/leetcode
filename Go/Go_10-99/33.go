// Go
// leetcode 33
// https://leetcode.cn/problems/search-in-rotated-sorted-array/

func search(nums []int, target int) int {
	n := len(nums)
	idx := search_helper(nums,0,n-1, target)
	if idx >= n || idx < 0 || nums[idx] != target {
		return -1
	}
    return idx
}

func search_helper(arr []int, l, r, t int) int {
    // fmt.Println(l, r)
	if l == r {
		if arr[l] == t {
			return l
		}
		return -1
	}
	if arr[l] < arr[r] {
		return biSearch(arr, l, r, t)
	}
	if arr[l] == t {
		return l
	}
	if arr[r] == t {
		return r
	}

	mid := l + (r-l)/2
	if arr[l] < arr[mid] { // 左 good， 右旋转
		x := biSearch(arr, l ,r, t)
		if x != len(arr) && arr[x] == t {
			return x
		}
		return search_helper(arr, mid, r, t)
	}

	// 左旋转，右 good
	x := biSearch(arr, l, r, t)
	if x != len(arr) && arr[x] == t {
		return x
	}
	return search_helper(arr, l, mid, t)
}


func biSearch(arr []int, l, r, target int) int {
	for l < r {
		mid := l + (r-l)/2
		if arr[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}