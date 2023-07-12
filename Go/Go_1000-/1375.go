// Go
// leetcode 1375
// https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/

func numTimesAllBlue(flips []int) int {
	biggest := 0
	cnt := 0
	for i, x := range flips {
		biggest = max(biggest, x)
		if biggest == i +1 {
			cnt++
		}
	}
	return cnt
}

func max(a, b int) int {
	if a > b {
		return a 
	}
	return b
}