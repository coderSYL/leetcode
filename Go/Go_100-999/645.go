// Go
// leetcode 645
// https://leetcode-cn.com/problems/set-mismatch/

func findErrorNums(nums []int) []int {
	n := len(nums)
	cnt := make([]int, n+1)
	for _, x := range nums {
		cnt[x]++
	}

	res := make([]int, 2)
	for i := 1; i <= n; i++ {
		if cnt[i] == 2 {
			res[0] = i
		} else if cnt[i] == 0 {
			res[1] = i
		}
	}
	return res
}