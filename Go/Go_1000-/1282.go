// Go
// leetcode 1282
// https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/

func groupThePeople(groupSizes []int) (res [][]int) {
	m := make(map[int][]int)
	for i, v := range groupSizes {
		if len(m[v]) == 0 || len(m[v]) == v {
			m[v] = make([]int, 0, v)
		}
		m[v] = append(m[v], i)
		if len(m[v]) == v {
			res = append(res, m[v])
		}
	}
	return res
}