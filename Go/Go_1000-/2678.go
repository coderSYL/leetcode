// Go
// leetcode 2678
// https://leetcode.cn/problems/number-of-senior-citizens/

func countSeniors(details []string) int {
	cnt := 0
	for _, s := range details {
		if getAge(s[11], s[12]) > 60 {
			cnt++
		}
	}
	return cnt
}

func getAge(a, b byte) int {
	x, y := int(a-'0'), int(b-'0')
	return x*10 + y
}