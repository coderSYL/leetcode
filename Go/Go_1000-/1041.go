// Go
// leetcode 1041
// https://leetcode.cn/problems/robot-bounded-in-circle/

func isRobotBounded(instructions string) bool {
	x, y := 0, 0
	dirs := []int{12, 21, 10, 1}
	p := 0
	for _, c := range instructions {
		switch c {
		case 'R':
			p = (p + 1) % 4
		case 'L':
			p = (p + 3) % 4
		case 'G':
			dx, dy := dirs[p]/10-1, dirs[p]%10-1
			x += dx
			y += dy
		}
	}

	if x == 0 && y == 0 { // 回到原地
		return true
	}

	return p != 0
}