// Go
// leetcode 2511
// https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/

func captureForts(forts []int) int {
	empty := false
	cnt := 0
	res := 0
	started := false
	for _, x := range forts {
		if x != 0 {
			started = true
		}
		if !started {
			continue
		}
		switch x {
		case -1: // empty
			if empty {
				cnt = 0
			} else {
				res = max(res, cnt)
				empty = true
				cnt = 0
			}
		case 0:
			cnt++
		case 1:
			if !empty {
				cnt = 0
			} else {
				res = max(res, cnt)
				empty = false
				cnt = 0
			}
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