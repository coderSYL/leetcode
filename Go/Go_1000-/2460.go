// Go
// leetcode 2460
// https://leetcode.cn/problems/apply-operations-to-an-array/

func applyOperations(nums []int) []int {
	n := len(nums)
    for i:=0; i<n-1; i++ {
		if nums[i] == nums[i+1] {
			nums[i] *= 2
			nums[i+1] = 0
		}
	}
	
	var zeroCnt int
	for i, j := 0, 0; i < n; i++{
		if nums[i] == 0 {
			zeroCnt++
		} else {
			nums[j] = nums[i]
			j++
		}
	}
    fmt.Println(zeroCnt)
	for i:= n-zeroCnt; i<n; i++ {
		nums[i] = 0
	}
	return nums
}