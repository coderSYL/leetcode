import "sort"

// Go
// leetcode 719
// https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

func smallestDistancePair(nums []int, k int) int {
	sort.Ints(nums)
	n := len(nums)
	l, r, mid, cnt := 0, nums[n-1]-nums[0], 0, 0
	for l < r {
		mid = (l + r) >> 1
		cnt = 0
		for i, j := 0, 0; i < n; i++ {
			for j < n && nums[j]-nums[i] <= mid {
				j++
			}
			cnt += j - i - 1
		}
		if cnt >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return r
}