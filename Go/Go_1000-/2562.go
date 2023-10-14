// Go
// leetcode 2562
// https://leetcode.cn/problems/find-the-array-concatenation-value/

func findTheArrayConcVal(nums []int) (res int64) {
	for i, j:= 0, len(nums)-1; i<=j; i, j = i+1, j-1{
		if i == j {
			res += int64(nums[i])
			continue
		}
		res += getNew(nums[i], nums[j])
		
	}

	return res
}

func getNew(a, b int) int64 {
	x := b
	for x > 0 {
		a *= 10
		x /= 10
	}

	return int64(a + b)
}