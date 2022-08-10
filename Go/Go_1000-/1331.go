// Go
// leetcode 1331
// https://leetcode.cn/problems/rank-transform-of-an-array/

func arrayRankTransform(arr []int) []int {
	n := len(arr)
	res := make([]int, n)
	copy(res, arr)
	sort.Ints(arr)

	// 把排名录入 map m中
	m := make(map[int]int, n)
	idx := 1
	for _, v := range arr {
		if _, ok := m[v]; ok {
			continue
		}

		m[v] = idx
		idx++
	}

	// 填入答案
	for i := 0; i < n; i++ {
		res[i] = m[res[i]]
	}

	return res
}