// Go
// leetcode 12
// https://leetcode.cn/problems/integer-to-roman/

func intToRoman(num int) (res string) {
	values := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	strs := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	for i := 0; i < 13; i++ {
		for num >= values[i] {
			num -= values[i]
			res += strs[i]
		}
	}
	return res
}