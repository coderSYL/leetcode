// Go
// leetcode 2418
// https://leetcode.cn/problems/sort-the-people/

func sortPeople(names []string, heights []int) []string {
	indexOfHeight := make(map[int]int)
	for i := 0; i < len(names); i++ {
		indexOfHeight[heights[i]] = i
	}
	sort.Ints(heights)
	res := []string{}
	for i := len(heights) - 1; i >= 0; i-- {
		res = append(res, names[indexOfHeight[heights[i]]])
	}
	return res
}