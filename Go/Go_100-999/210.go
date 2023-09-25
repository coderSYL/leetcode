// Go
// leetcode 210
// https://leetcode.cn/problems/course-schedule-ii/

func findOrder(n int, prerequisites [][]int) []int {
	taken := make([]bool, n)
	res := make([]int, 0, n)
	next := make([][]int, n)
	inDeg := make([]int, n)
	for _, p := range prerequisites {
		a, b := p[1], p[0] // 上完 a 才能上 b
		next[a] = append(next[a], b)
		inDeg[b]++
	}

	for len(res) < n {
		cur := 0 // 本轮上的课的数量

		for i:=0; i<n; i++ {
			if taken[i] { // 上过
				continue
			}

			if inDeg[i] != 0 { // 需要前置课程
				continue
			}

			taken[i] = true
			cur++
			res = append(res, i)
			for _, x := range next[i] {
				inDeg[x]--
			}
		}
		if cur == 0 {
			break
		}
	}

	if len(res) != n {
		return []int{}
	}

	return res
}