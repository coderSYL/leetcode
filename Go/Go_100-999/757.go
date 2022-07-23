// Go
// leetcode 757
// https://leetcode.cn/problems/set-intersection-size-at-least-two/

func intersectionSizeTwo(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][1] != intervals[j][1] {
			return intervals[i][1] < intervals[j][1]
		}
		return intervals[i][0] > intervals[j][0]
	})

	a, b, res := -1, -1, 0

	for i := 0; i < len(intervals); i++ {
		if intervals[i][0] > b {
			a = intervals[i][1] - 1
			b = intervals[i][1]
			res += 2
		} else if intervals[i][0] > a {
			a = b
			b = intervals[i][1]
			res++
		}
	}

	return res
}