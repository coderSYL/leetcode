// Go
// leetcode 13
// https://leetcode.cn/problems/roman-to-integer/

func romanToInt(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}
	var values = []int{1000, 500, 100, 50, 10, 5, 1}
	var bytes = []byte{'M', 'D', 'C', 'L', 'X', 'V', 'I'}
	k := 0
	for i := 0; i < 7; i++ {
		startPoint, cnt := -1, 0
		for k = 0; k < n; k++ {
			if s[k] == bytes[i] {
				cnt++
				if startPoint == -1 {
					startPoint = k
				}
			} else if cnt > 0 {
				break
			}
		}
		if cnt > 0 {
			var left, right string
			if startPoint != 0 {
				left = string(s[:startPoint])
			}
			if startPoint+cnt != n {
				right = string(s[startPoint+cnt:])
			}
			return cnt*values[i] - romanToInt(left) + romanToInt(right)
		}
	}
	return 0
}