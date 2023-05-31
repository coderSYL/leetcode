// Go
// leetcode 970
// https://leetcode.cn/problems/powerful-integers/

func powerfulIntegers(x int, y int, bound int) []int {
	if x == 1 {
		x, y = y, x
	}
	if x == 1 {
		switch bound {
		case 0, 1:
			return []int{}
		default:
			return []int{2}
		}
	}
	m := make(map[int]bool)
	for xPart := 1; xPart < bound; {
		yPart := 1
		if y == 1 {
			m[xPart+1] = true
		} else {
			for xPart+yPart <= bound {
				m[xPart+yPart] = true
				yPart *= y
			}
		}
		xPart *= x
	}
	res, p := make([]int, len(m)), 0
	for i, _ := range m {
		res[p] = i
		p++
	}
	return res
}