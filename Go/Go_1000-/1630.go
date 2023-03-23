// Go
// leetcode 1630
// https://leetcode.cn/problems/arithmetic-subarrays/

func checkArithmeticSubarrays(nums []int, l []int, r []int) []bool {
	n := len(l)
	res := make([]bool, n)
	for i := 0; i < n; i++ {
		left, right := l[i], r[i]
		res[i] = isGood(nums[left : right+1])
	}
	return res
}

func isGood(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return true
	}
	min1, min2 := 200_000, 200_000
	for _, x := range nums {
		if x < min1 {
			min1, min2 = x, min1
		} else if x < min2 {
			min2 = x
		}
	}
	d := min2 - min1
	if d == 0 { // 常数列
		for _, x := range nums {
			if x != min1 {
				return false
			}
		}
		return true
	}

	visited := make([]bool, n)
	for _, x := range nums {
        if (x-min1) % d != 0 {
            return false
        }
		x = (x-min1) / d
		if x >= n || visited[x] {
			return false
		}
		visited[x] = true
	}
	return true
}