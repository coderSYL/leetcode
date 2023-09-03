// Go
// leetcode 128
// https://leetcode.cn/problems/longest-consecutive-sequence/

func longestConsecutive(nums []int) int {
	findRight, findLeft := make(map[int]int), make(map[int]int)
    vis := make(map[int]bool)
	res := 0
	update := func(x int) {
        if vis[x] {
            return
        }
        vis[x] =true
		l, r, ok := x, x, true
		l, ok = findLeft[x-1]
		if ok {
			delete(findLeft, x-1)
		} else {
			l = x
		}
		r, ok = findRight[x+1]
		if ok {
			delete(findRight, x+1)
		} else {
			r = x
		}
		findLeft[r] = l
		findRight[l] = r
		res = max(res, r -l + 1)
	}

	for _, x := range nums {
		update(x)
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}