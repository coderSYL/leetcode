// Go
// leetcode 1138
// https://leetcode.cn/problems/alphabet-board-path/

func alphabetBoardPath(target string) string {
	x, y := 0, 0
	var res []byte
	for _, c := range target {
		u := int(c - 'a')
		nx, ny := u/5, u%5
		if x == 5 && nx != 5 {
			x--
			res = append(res, 'U')
		}
		for y < ny {
			y++
			res = append(res, 'R')
		}
		for y > ny {
			y--
			res = append(res, 'L')
		}
		for x < nx {
			x++
			res = append(res, 'D')
		}
		for x > nx {
			x--
			res = append(res, 'U')
		}
		res = append(res, '!')
	}
	return string(res)
}