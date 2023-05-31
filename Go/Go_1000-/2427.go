// Go
// leetcode 2427
// https://leetcode.cn/problems/number-of-common-factors/

func commonFactors(a int, b int) int {
	cur := 2
	arr := []int{}
	for cur <= a && cur <= b {
		cnt := 0
		for a%cur == 0 && b%cur == 0 {
			a, b = a/cur, b/cur
			cnt++
		}
		if cnt > 0 {
			arr = append(arr, cnt)
		}
		cur++
	}
	res := 1
	for _, x := range arr {
		res *= x + 1
	}
	return res
}