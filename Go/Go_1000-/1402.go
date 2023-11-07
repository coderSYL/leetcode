// Go
// leetcode 1402
// https://leetcode.cn/problems/reducing-dishes/

func maxSatisfaction(satisfaction []int) int {

	sort.Ints(satisfaction)
	n := len(satisfaction)
	negativeCnt := 0
	for negativeCnt < n && satisfaction[negativeCnt] <0 {
		negativeCnt++
	}

	positiveSum := 0
	res := 0
	for i:=negativeCnt; i < n; i++ {
		res += (i-negativeCnt+1) * satisfaction[i]
		positiveSum += satisfaction[i]
	}

	start:= negativeCnt-1
	negaSum := 0

	for start >= 0 {
		negaSum += satisfaction[start]
		if negaSum + positiveSum < 0 {
			break
		}
		start--
	}


	m := negativeCnt - start - 1 // 选用的负数的数量
	for i:= negativeCnt-1; i> start; i-- {
		res += (m + 1 - (negativeCnt - i)) * satisfaction[i]
	}
	res += positiveSum * m // 因此而增加的正数区域的满意度
	return res
}