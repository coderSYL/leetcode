// Go
// leetcode 2379
// https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

func minimumRecolors(blocks string, k int) int {
	n, cnt := len(blocks), 0
	for i := 0; i < k; i++ {
		if blocks[i] == 'W' {
			cnt++
		}
	}
	res := cnt
	for i := k; i < n; i++ {
		if blocks[i] == 'W' {
			cnt++
		}
		if blocks[i-k] == 'W' {
			cnt--
			res = min(res, cnt)
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}