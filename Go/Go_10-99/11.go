// Go
// leetcode 11
// https://leetcode.cn/problems/container-with-most-water/

func maxArea(height []int) (res int) {
	left, right := 0, len(height)-1
	for left < right {
		lowerHight := min(height[left], height[right])
		res = max(res, lowerHight*(right-left))
		for left < right && height[left] <= lowerHight {
			left++
		}
		for left < right && height[right] <= lowerHight {
			right--
		}
	}
	return res
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}