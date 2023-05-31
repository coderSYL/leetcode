// Go
// leetcode 1027
// https://leetcode.cn/problems/longest-arithmetic-subsequence/

func longestArithSeqLength(nums []int) (res int) {
	size := make(map[int]int) // key = end + diff * 501
	for _, x := range nums {
		size[x]++
		res = max(res, size[x])
		for diff := x - 500; diff <= x; diff++ {
			if diff == 0 {
				continue
			}

			end := x - diff
			key := end + diff*501
			v, ok := size[key]
			if ok {
				size[key+diff] = v + 1
				res = max(res, v+1)
			} else {
				if size[end] > 0 {
					size[key+diff] = 2
					res = max(res, 2)
				}
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