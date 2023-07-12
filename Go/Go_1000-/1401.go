// Go
// leetcode 1401
// https://leetcode.cn/problems/circle-and-rectangle-overlapping/

func checkOverlap(radius int, xCenter int, yCenter int, x1 int, y1 int, x2 int, y2 int) bool {
	x, y := goodCor(xCenter, x1, x2), goodCor(yCenter, y1, y2)
	dis2 := sq(x - xCenter) + sq(y - yCenter)
	return dis2 <= sq(radius)
}

func goodCor(x, start, end int) int {
	if x < start {
		return start
	}
	if x > end {
		return end
	}
	return x
}

func sq(x int) int {
	return x * x
}