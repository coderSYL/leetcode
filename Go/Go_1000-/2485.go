// Go
// leetcode 2485
// https://leetcode.cn/problems/find-the-pivot-integer/

func pivotInteger(n int) int {
	l , r := 1, n
	totalSum := sumFromOne(n)
	for l <= r {
		mid := (l+r) >> 1
		leftSum := sumFromOne(mid-1)
		if totalSum - mid == 2 * leftSum {
			return mid
		}
		if totalSum - mid > 2 * leftSum {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return -1
}

func sumFromOne(x int) int {
	return x * (x+1) /2
}