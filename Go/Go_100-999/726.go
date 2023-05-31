// Go
// leetcode 726
// https://leetcode.cn/problems/number-of-atoms/

// import "strconv" // imported already

func countOfAtoms(formula string) string {
	parentheseNum := []int{}
	curNum := 1
	cnt := make(map[string]int)
	for i := len(formula) - 1; i >= 0; i-- {
		switch formula[i] {
		case ')':
			parentheseNum = append(parentheseNum, curNum)
			curNum = 1
		case '(':
			parentheseNum = parentheseNum[:len(parentheseNum)-1]
		default:
			if isNum(formula[i]) {
				j := i - 1
				for j >= 0 && isNum(formula[j]) {
					j--
				}
				curNum, _ = strconv.Atoi(formula[j+1 : i+1])
				i = j + 1
			} else {
				j := i
				for !isBigLetter(formula[j]) {
					j--
				}
				element := formula[j : i+1]
				for _, x := range parentheseNum {
					curNum *= x
				}
				cnt[element] += curNum
				curNum = 1
				i = j
			}
		}
	}
	res := ""
	var ss []string
	for element, num := range cnt {
		if num != 1 {
			element += strconv.Itoa(num)
		}
		ss = append(ss, element)
	}
	sort.Strings(ss)
	for _, s := range ss {
		res += s
	}
	return res
}

func isNum(c byte) bool {
	return c >= '0' && c <= '9'
}

func isBigLetter(c byte) bool {
	return c >= 'A' && c <= 'Z'
}