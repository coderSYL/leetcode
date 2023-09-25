// Go
// leetcode 57
// https://leetcode.cn/problems/insert-interval/

func insert(intervals [][]int, newInterval []int) [][]int {
	// 把新区间加到正确的位置
	intervals = append(intervals, newInterval)
	a, b := newInterval[0], newInterval[1]
	goodIndex := 0
	n := len(intervals)
	for goodIndex < n && intervals[goodIndex][0] < a {
		goodIndex++
	}
	for i := n - 2; i >= goodIndex; i-- {
		intervals[i+1][0], intervals[i+1][1] = intervals[i][0], intervals[i][1]
	}
	if goodIndex != n {
		intervals[goodIndex][0], intervals[goodIndex][1] = a, b
	}

	// 合并重叠区间
	p, q := n, n
	for i := 0; i < n-1; i++ {
		// fmt.Println(i)
		j := i
		for j < n && intervals[j][0] <= intervals[i][1] {
			intervals[i][1] = max(intervals[i][1], intervals[j][1])
			j++
		}
		if j != i+1 {
			p, q = i+1, j
			break
		}
	}
	for q < n {
		intervals[p][0], intervals[p][1] = intervals[q][0], intervals[q][1]
		p++
		q++
	}
	intervals = intervals[:n-(q-p)]
	return intervals
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}