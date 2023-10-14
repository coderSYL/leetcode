// Go
// leetcode 2136
// https://leetcode.cn/problems/earliest-possible-day-of-full-bloom/

func earliestFullBloom(plantTime []int, growTime []int) int {
	n := len(plantTime)
	order := make([]int, n)
	for i, _ := range order {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		a, b := order[i], order[j]
		return growTime[a] >= growTime[b]
	})

	res := 0
	cur := 0
	for _, x := range order {
		cur += plantTime[x]
		res = max(res, cur + growTime[x])
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}