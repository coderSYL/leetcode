// Go
// leetcode 658
// https://leetcode.cn/problems/find-k-closest-elements/

func findClosestElements(arr []int, k int, x int) []int {
	n := len(arr)

	// arr 数组整体大于 x 或者整体小于 x
	if arr[0] >= x {
		return arr[0 : k]
	} else if arr[n - 1] <= x {
		return arr[n - k : n]
	}

	// 二分法找到最接近 x 的数的为止
	l, r := 0, n - 1
	for l <= r {
		mid := (l + r)>>1
		if arr[mid] == x {
			l = mid
			r = mid
			break
		} else if arr[mid] > x {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}

	if abs(arr[r] - x) <= abs(arr[l] - x) {
		l = r - 1
		r++
	} else {
		r = l + 1
		l--
	}

	// 从一个数字扩散到 k 个连续数字
	for r - l - 1 < k {
		if l == -1 {
			r++
		} else if (r == n) {
			l--
		} else {
			if (abs(arr[l] - x) <= abs(arr[r] - x)) {
				l--
			} else {
				r++
			}
		}
	}

	return arr[l + 1 : r]
}

// 返回 x 的绝对值
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}