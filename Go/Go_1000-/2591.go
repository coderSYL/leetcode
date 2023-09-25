// Go
// leetcode 2591
// https://leetcode.cn/problems/distribute-money-to-maximum-children/

func distMoney(money int, children int) int {
	if children * 8 == money +4 { // 一4其他8
		return children-2
	}
	if children * 8 == money { // 全8
		return children
	}

	money -= children

	if money < 0 { // 钱不够分
		return -1
	}

	cnt := money / 7
	if cnt < children {
		return cnt
	}
	
	return children-1
}