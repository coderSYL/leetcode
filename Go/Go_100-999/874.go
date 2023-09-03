// Go
// leetcode 874
// https://leetcode.cn/problems/walking-robot-simulation/

func robotSim(commands []int, obstacles [][]int) int {
	isBadPosition := map[int]bool{} // 障碍的数据结构
	setBad := func(x, y int) {
		u := (x + 30_000) * 100_000 + y + 30_000
		isBadPosition[u] = true
	}
	isBad := func(x, y int) bool {
		u := (x + 30_000) * 100_000 + y + 30_000
		_, ok := isBadPosition[u]
		return ok
	}

	dirs := [][]int{{0,1}, {1, 0}, {0, -1}, {-1, 0}} // 方向的数据结构
	p := 0
	turnLeft := func() {
		p = (p + 3) % 4
	}
	turnRight := func() {
		p = (p+1) % 4
	}

	for _, p := range obstacles { // 录入所有障碍的信息
		setBad(p[0], p[1])
	}

	res := 0
	x, y := 0, 0 // 当前位置
	for _, c := range commands {
		// 右转
		if c == -1 { 
			turnRight()
			continue
		}

		// 左转
		if c == -2 {
			turnLeft()
			continue
		}

		var nx, ny int
		for c > 0 { // 步数没走完
			c--
			nx = x + dirs[p][0]
			ny = y + dirs[p][1]
			if isBad(nx, ny) { // 会遇上障碍
				break
			}
			x, y = nx, ny
		}
		res = max(res, x*x + y*y)
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}