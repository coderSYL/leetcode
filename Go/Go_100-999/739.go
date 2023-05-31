// Go
// leetcode 739
// https://leetcode.cn/problems/daily-temperatures/

func dailyTemperatures(temperatures []int) []int {
	n := len(temperatures)
	res := make([]int, n)
	stk := []int{}
	top := func() int {
		return stk[len(stk)-1]
	}
	out := func() {
		stk = stk[:len(stk)-1]
	}
	for i := n - 1; i >= 0; i-- {
		for len(stk) != 0 {
			if temperatures[top()] <= temperatures[i] {
				out()
			} else {
				break
			}
		}
		if len(stk) == 0 {
			res[i] = 0
		} else {
			res[i] = top() - i
		}
		// fmt.Println(i, res[i])
		stk = append(stk, i)
	}
	return res
}