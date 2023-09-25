// Go
// leetcode 1222
// https://leetcode.cn/problems/queens-that-can-attack-the-king/

func queensAttacktheKing(queens [][]int, king []int) [][]int {
	haveQueen := make([]bool, 64)

	dirs := []int{-1, 0, 1, 0, -1, 1, 1, -1, -1} // 8个方向
	done := make([]bool, 8)

	for _, p:= range queens { // 皇后数据录入
		x, y := p[0],p[1]
		haveQueen[x*8 + y] = true
	}

	check := func(a, b int) bool { // 判断坐标 (a, b) 是否有皇后
		if b < 0 || b >= 8 || a < 0 || a >= 8{
			return false
		}
		return haveQueen[a*8 + b]
	}

	x, y := king[0], king[1]

	res := [][]int{}
	update := func(a, b int) {
		res = append(res, []int{a, b})
	}

	for i:=1; i<8; i++ {
		for p:=0; p<8; p++ {
			if done[p] {
				continue
			}
			a, b := x + i * dirs[p], y + i * dirs[p+1]
			if check(a, b) {
				update(a, b)
				done[p] = true
			}
		}
	}

	return res
}