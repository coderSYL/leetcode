func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 返回有序数组 arr 中，第一个大于等于 target 的元素的索引
// 若所有元素均小于 target，返回 n = len(arr)
func lower_bound(arr []int, target int) int {
	n := len(arr)
	l, r := 0, n
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