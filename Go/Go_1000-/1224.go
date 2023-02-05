// Go
// leetcode 1224
// https://leetcode.cn/problems/maximum-equal-frequency/

func maxEqualFreq(nums []int) int {
	mx, res := 0, 0
	cnt, sum := make([]int, 100009), make([]int, 100009)
	for i, x := range nums {
		cnt[x]++
		len, cur := i+1, cnt[x]
		sum[cur-1]--
		sum[cur]++
		mx = max(mx, cur)

		// check
		if mx == 1 {
			res = len
		} else if mx*sum[mx] == i {
			res = len
		} else if (mx-1)*(sum[mx-1]+1) == i {
			res = len
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}