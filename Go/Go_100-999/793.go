// Go
// leetcode 793
// https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/
// 经典二分

// 计算 (5 * x)! 的结尾有多少个 0
func get5(x int64) (res int64) {
	for x > 0 {
		res += x
		x /= 5
	}
	return res
}

func preimageSizeFZF(k int) int {
	var l, r, kk int64 = 0, int64(k), int64(k)

	for l <= r {
		mid := (r-l)/2 + l
		x := get5(mid)
		if x == kk {
			return 5
		} else if x < kk {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	// 没找到
	return 0
}