// Go
// leetcode 1262
// https://leetcode.cn/problems/greatest-sum-divisible-by-three/

func maxSumDivThree(nums []int) int {
	sum := 0
	min1 := []int{100_000, 100_000}
	In1 := func(x int) {
		min1[1] = min(min1[1], x)
		min1[0], min1[1] = min(min1[0], min1[1]), max(min1[0], min1[1])
	}

	min2 := []int{100_000, 100_000}
	In2 := func(x int) {
		min2[1] = min(min2[1], x)
		min2[0], min2[1] = min(min2[0], min2[1]), max(min2[0], min2[1])
	}

	for _, x := range nums {
		sum += x
		switch x%3 {
		case 0:
		case 1:
			In1(x)
		case 2:
			In2(x)
		}
	}

	switch sum % 3 {
	case 0:
		return sum
	case 1:
		return sum - min(min1[0], min2[0] + min2[1])
	case 2:
		return sum - min(min1[0]+min1[1], min2[0])
	}
	return -1 // never
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}