// Go
// leetcode 1037
// https://leetcode.cn/problems/valid-boomerang/

func isBoomerang(points [][]int) bool {
	dx_1, dy_1 := points[1][0]-points[0][0], points[1][1]-points[0][1]
	dx_2, dy_2 := points[2][0]-points[0][0], points[2][1]-points[0][1]
	if dx_1*dy_2 == dx_2*dy_1 {
		return false
	}
	return true
}