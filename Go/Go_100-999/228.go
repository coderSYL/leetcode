// Go
// leetcode 228
// https://leetcode.cn/problems/summary-ranges/

import "strconv"

func summaryRanges(nums []int) (res []string) {
	if len(nums) == 0 {
		return
	}

	a, b := nums[0], nums[0]
	update := func() {
		if a == b {
			res = append(res, strconv.Itoa(a))
		} else {
			res = append(res, strconv.Itoa(a)+"->"+strconv.Itoa(b))
		}
	}
	for i := 1; i < len(nums); i++ {
		x := nums[i]
		if x == b+1 {
			b++
			continue
		}
		update()
		a, b = x, x
	}
	update()
	return res
}