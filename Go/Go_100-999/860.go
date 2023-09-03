// Go
// leetcode 860
// https://leetcode.cn/problems/lemonade-change/

func lemonadeChange(bills []int) bool {
	five, ten := 0, 0
	for _, x := range bills {
		switch x {
		case 5:
			five++
		case 10:
			five--
			
			ten++
		case 20:
			need := 15
			if ten > 0 {
				ten--
				need -= 10
			}
			five -= need / 5
		}
		if five < 0 {
			return false
		}
	}
	return true
}