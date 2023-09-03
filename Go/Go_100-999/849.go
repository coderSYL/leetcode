// Go
// leetcode 849
// https://leetcode.cn/problems/maximize-distance-to-closest-person/

func maxDistToClosest(seats []int) int {
	pre := -1
	mx := 0
	for i, x := range seats {
		if x == 0 {
			continue
		}
		// fmt.Println(pre)
		switch pre {
		case -1:
			mx = max(mx, i)
		default:
			mx = max(mx, (i-pre)/2)
		}
		pre =i
	}
	mx = max(mx, len(seats)-pre-1)
	return mx
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}