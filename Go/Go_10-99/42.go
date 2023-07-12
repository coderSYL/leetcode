// Go
// leetcode 42
// https://leetcode.cn/problems/trapping-rain-water/

func trap(height []int) int {
	n := len(height)
	preMax := make([]int, n)
	sufMax := make([]int, n)
	preMax[0] = height[0]
	for i := 1; i < n; i++ {
		preMax[i] = max(preMax[i-1], height[i])
	}

	sufMax[n-1] = height[n-1]
	for i := n - 2; i >= 0; i-- {
		sufMax[i] = max(sufMax[i+1], height[i])
	}

	res := 0
	for i := 0; i < n; i++ {
		waterHeight := min(preMax[i], sufMax[i])
		if waterHeight > height[i] {
			res += waterHeight - height[i]
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// // 方法二，省空间
// func trap(height []int) int {
// 	n := len(height)
// 	left, right := 0, n-1
// 	preMax := 0
// 	sufMax := 0
// 	res := 0
// 	for left <= right {
// 		preMax = max(preMax, height[left])
// 		sufMax = max(sufMax, height[right])
// 		if preMax < sufMax {
// 			res += preMax - height[left]
// 			left++
// 		} else {
// 			res += sufMax - height[right]
// 			right--
// 		}
// 	}
// 	return res
// }

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }