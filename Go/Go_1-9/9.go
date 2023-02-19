// Go
// leetcode 9
// https://leetcode.cn/problems/palindrome-number/

func isPalindrome(x int) bool {
	x64 := int64(x)
	if x64 < 0 {
		return false
	}
	var y int64
	for x64 > 0 {
		y = y*10 + x64%10
		x64 /= 10
	}
	return y == int64(x)
}