// Go
// leetcode 56
// https://leetcode.cn/problems/merge-intervals/

func merge(intervals [][]int) (res [][]int) {
	// 排序
	sort.Slice(intervals, func(i, j int) bool {
		a, b := intervals[i], intervals[j]
		if a[0] != b[0] {
			return a[0] < b[0]
		}
		return a[1] < b[1]
	})

	// fmt.Println(intervals)
	preA, preB := intervals[0][0], intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		a, b := intervals[i][0], intervals[i][1]
		if a <= preB {
			preB = max(b, preB)
			continue
		}

		res = append(res, []int{preA, preB})
		preA, preB = a, b
	}
	res = append(res, []int{preA, preB})

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}