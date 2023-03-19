// Go
// leetcode 2488
// https://leetcode.cn/problems/count-subarrays-with-median-k/

func countSubarrays(nums []int, k int) int {
	idxForK := 0
	for nums[idxForK] != k {
		idxForK++
	}
	
	n := len(nums)
	cnt := make([]int, 2 * n) // [-n ,n-1]
	cnt[n] = 1
	cur := n
	for i := idxForK-1; i >= 0; i-- {
		if nums[i] < k {
			cur++
		} else {
			cur--
		}
		cnt[cur]++
	}

	res := cnt[n] + cnt[n-1]
	cur = n
	for _, x := range nums[idxForK+1:] {
		if x > k {
			cur++
		} else {
			cur--
		}
		res += cnt[cur] + cnt[cur-1]
        // if x > 0 {
        //     res += cnt[x-1]
        // }
	}

	return res
}