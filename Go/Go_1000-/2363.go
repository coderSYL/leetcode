// Go
// leetcode 2363
// https://leetcode.cn/problems/merge-similar-items/

func mergeSimilarItems(items1 [][]int, items2 [][]int) [][]int {
	weightCnt := make([]int, 1001)
	for _, p := range items1 {
		weightCnt[p[0]] += p[1]
	}
	for _, p := range items2 {
		weightCnt[p[0]] += p[1]
	}

	res := make([][]int, 0, 4)
	for val := 1; val <= 1000; val++ {
		if weightCnt[val] > 0 {
			res = append(res, []int{val, weightCnt[val]})
		}
	}
	return res
}