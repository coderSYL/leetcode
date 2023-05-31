// Go
// leetcode 2395
// https://leetcode.cn/problems/find-subarrays-with-equal-sum/

func findSubarrays(nums []int) bool {
	vis := make(map[int]bool)
	for i := len(nums) - 1; i > 0; i-- {
		x := nums[i] + nums[i-1]
		if vis[x] {
			return true
		}
		vis[x] = true
	}
	return false
}