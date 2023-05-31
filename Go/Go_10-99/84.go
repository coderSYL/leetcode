// Go
// leetcode 84
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
// 单调栈，确保栈内元素都比新进栈的要小，要是大了，就可以掏出来结算，必要的话更新res
// 小技巧，开始先给h的结尾加个0，确保所有的都能结算

func largestRectangleArea(h []int) (res int) {
	h = append(h, 0)
	stk := []int{}
	for i, _ := range h {
		for len(stk) != 0 && h[stk[len(stk)-1]] > h[i] {
			tmp := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			width := i
			if len(stk) != 0 {
				width -= stk[len(stk)-1] + 1
			}
			res = max(res, h[tmp]*width)
		}
		stk = append(stk, i)
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}