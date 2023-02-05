// Go
// leetcode 946
// https://leetcode.cn/problems/validate-stack-sequences/

func validateStackSequences(pushed []int, popped []int) bool {
	// 模拟栈
	stk := make([]int, 0, 4)

	var p int // popped 的指针
	for _, v := range pushed {
		// 入栈一个数字
		stk = append(stk, v)

		// 能出栈的全出了
		pp := len(stk) - 1
		for pp >= 0 && popped[p] == stk[pp] {
			pp--
			p++
		}
		stk = stk[0 : pp+1]
	}

	return len(stk) == 0 // 栈空则代表能按照顺序出完
}