// Go
// leetcode 646
// https://leetcode.cn/problems/maximum-length-of-pair-chain/

func findLongestChain(pairs [][]int) (res int) {
	n := len(pairs)
	sort.Slice(pairs, func(i, j int) bool { return pairs[i][0] < pairs[j][0]})
	g := make([]int, n + 5)
	for i := 0; i < n + 5; i++ {
		g[i] = 0x3f3f3f3f
	}
	for i := 0; i < n; i++ {
		l, r := 1, i + 1
		x := pairs[i][0]
		for l < r {
			mid := (l + r) >> 1
			if g[mid] >= x {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if g[r] > pairs[i][1] {
			g[r] = pairs[i][1]
		}
		if r > res {
			res = r
		}
	}
	return res
}