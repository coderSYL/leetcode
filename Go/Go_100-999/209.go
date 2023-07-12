// Go
// leetcode 209
// https://leetcode-cn.com/problems/minimum-size-subarray-sum/

func minSubArrayLen(target int, nums []int) int {
	res := 1000_000
	n := len(nums)
	curSum :=0
	for l, r:=0, 0; l < n; {
		for r < n && curSum < target {
			curSum += nums[r]
			r++
		}
		
		if curSum < target {
			break
		}
		
        for l < n && curSum >= target {
            curSum -= nums[l]
            l++
        }
        res = min(res, r-l+1)
		
	}
	
	if res == 1000_000 {
		return 0
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}