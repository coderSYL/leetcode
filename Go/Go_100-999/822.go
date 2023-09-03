// Go
// leetcode 822
// https://leetcode.cn/problems/card-flipping-game/

func flipgame(fronts []int, backs []int) int {
	bad := map[int]bool{}
	for i := range fronts {
		if fronts[i] == backs[i] {
			bad[fronts[i]] = true
		}
	}
	isGood := func(x int) bool {
		_, ok := bad[x]
		return !ok
	}

	res := 4000
	for i := range fronts {
		a, b := fronts[i], backs[i]
		if isGood(a) {
			res = min(res, a)
		}
		if isGood(b) {
			res = min(res, b)
		}
	}

	if res == 4000 {
		return 0
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// // 方法二（数据范围足够小）
// func flipgame(fronts []int, backs []int) int {
// 	isGood := make([]bool, 2001)
// 	isBad := make([]bool, 2001)
// 	for i:=range fronts {
// 		a, b := fronts[i], backs[i]
// 		if a == b {
// 			isBad[a] = true
// 			continue
// 		}
// 		isGood[a] = true
// 		isGood[b] = true
// 	}
// 	for i:=1; i<=2000; i++ {
// 		if isGood[i] && !isBad[i] {
// 			return i
// 		}
// 	}
// 	return 0
// }