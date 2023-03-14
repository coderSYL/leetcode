// Go
// leetcode interview 17.05
// https://leetcode.cn/problems/find-longest-subarray-lcci/

func findLongestSubarray(array []string) []string {
	cur := 0
	firstIndexForVal := make(map[int]int)
	firstIndexForVal[0] = -1
	goodLeft, goodRight := 0, 0
	for i, r := range array {
		if isNum(r) {
			cur++
		} else {
			cur--
		}
		if l, ok := firstIndexForVal[cur]; ok {
			if i-l > goodRight-goodLeft {
				goodLeft, goodRight = l+1, i+1
			}
		} else {
			firstIndexForVal[cur] = i
		}
	}
	return array[goodLeft: goodRight]
}

func isNum(s string) bool {
	if s[0] >= '0' && s[0] <= '9' {
		return true
	}
	return false
}