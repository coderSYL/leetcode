import "sort"

// Go
// leetcode 532
// https://leetcode.cn/problems/k-diff-pairs-in-an-array/

func findPairs(nums []int, k int) int {
	res := 0
	// case k == 0
	if k == 0 {
		cnt := make(map[int]int)
		for _, x := range nums {
			cnt[x]++
			if cnt[x] == 2 {
				res++
			}
		}
		return res
	}
	// other case
	sort.Ints(nums)
	n := len(nums)
	for i, j := 0, 1; j < n && i < n; i++ {
		for (j < n) && (nums[j]-nums[i]) < k {
			j++
		}
		if j < n && nums[j]-nums[i] == k {
			res++
		}
		for k != 0 && i+1 < n && nums[i] == nums[i+1] {
			i++
		}
	}
	return res
}