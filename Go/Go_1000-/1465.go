// Go
// leetcode 1465
// https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
	sort.Ints(horizontalCuts)
	sort.Ints(verticalCuts)
	hLen, vLen := len(horizontalCuts), len(verticalCuts)

	hMax := max(horizontalCuts[0], h-horizontalCuts[hLen-1])
	for i:=0; i<hLen-1; i++ {
		hMax = max(hMax, horizontalCuts[i+1] - horizontalCuts[i])
	}

	vMax := max(verticalCuts[0], w-verticalCuts[vLen-1])
	for i:=0; i<vLen-1; i++ {
		vMax = max(vMax, verticalCuts[i+1] - verticalCuts[i])
	}

	return (hMax * vMax) % 1000_000_007
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}