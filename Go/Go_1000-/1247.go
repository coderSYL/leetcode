// Go
// leetcode 1247
// https://leetcode.cn/problems/minimum-swaps-to-make-strings-equal/

func minimumSwap(s1 string, s2 string) int {
	cnt := make([]int, 2)
	n := len(s1)
	for i := 0; i < n; i++ {
		if s1[i] != s2[i] {
			cnt[int(s1[i]&1)]++
		}
	}

	d := cnt[0] + cnt[1]

	if d&1 == 1 {
		return -1
	}
	return (d >> 1) + cnt[0]%2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}