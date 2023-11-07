// Go
// leetcode 274
// https://leetcode.cn/problems/h-index/

func hIndex(citations []int) int {
	cnt := make([]int, 1005)
	for _, x := range citations {
		cnt[x]++
	}

	sum := 0
	for i:=1000; i>=0; i-- {
		sum += cnt[i]
		if sum >= i {
			return i
		}
	}
	return 0
}