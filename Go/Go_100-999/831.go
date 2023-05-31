// Go
// leetcode 831
// https://leetcode.cn/problems/masking-personal-information/

import (
	"strconv"
)

func maskPII(s string) string {
	altIndex := -1
	bs := []byte(s)
	nums := []int{}
	for i := 0; i < len(bs); i++ {
		var isNum bool
		bs[i], isNum = big2SmallAndCheckNum(bs[i])
		if bs[i] == '@' {
			altIndex = i
		}
		if isNum {
			nums = append(nums, int(bs[i]-'0'))
		}
	}
	if len(nums) != 0 { // tel number case
		return getTelNum(nums)
	}

	// email case
	email := string(bs[0:1]) + "*****" + string(bs[altIndex-1:])
	return email
}

func big2SmallAndCheckNum(b byte) (byte, bool) { // if b is big letter
	var isNum bool = b >= '0' && b <= '9'
	if b >= 'A' && b <= 'Z' {
		return b - 'A' + 'a', isNum
	}
	return b, isNum
}

func getTelNum(tel []int) (res string) {
	n := len(tel)
	local4 := strconv.Itoa(tel[n-4]) + strconv.Itoa(tel[n-3]) + strconv.Itoa(tel[n-2]) + strconv.Itoa(tel[n-1])
	switch n {
	case 10:
		res = "***-***-" + local4
	case 11:
		res = "+*-***-***-" + local4
	case 12:
		res = "+**-***-***-" + local4
	case 13:
		res = "+***-***-***-" + local4
	}
	return res
}