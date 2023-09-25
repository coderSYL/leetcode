// Go
// leetcode 2560
// https://leetcode.cn/problems/house-robber-iv/

func minCapability(nums []int, k int) int {
	return sort.Search(1000_000_000, func(mx int) bool {
		cnt, n := 0, len(nums)
		for i := 0; i < n; i++ {
			if nums[i] <= mx {
				cnt++ // 偷 nums[i]
				i++   // 跳过下一间房子
			}
		}
		return cnt >= k
	})
}