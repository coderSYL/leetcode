// Go
// leetcode 448
// https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/

func findDisappearedNumbers(nums []int) (res []int) {
	n := len(nums)
	cnt := make([]int, n + 1)
	for _, x := range nums {
		cnt[x]++
	}
	for i := 1; i <= n; i++ {
		if cnt[i] == 0 {
			res = append(res, i)
		}
	}
	return res
}