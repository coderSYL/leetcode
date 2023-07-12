// Go
// leetcode 2496
// https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/

func maximumValue(strs []string) int {
	res := 0
	for _, s := range strs {
		res = max(res, helper(s))
	}

	return res
}

func helper(s string) int {
	n := len(s)
	res := 0
	base := 1
	for i:=n-1; i>=0; i-- {
		if i != n-1 {
			base *= 10
		}
		u := int(s[i]-'0')

		if u < 0 || u > 9 {
			return n
		}
		res += base * u
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}