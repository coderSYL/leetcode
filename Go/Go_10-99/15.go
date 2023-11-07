// Go
// leetcode 15
// https://leetcode.cn/problems/3sum/

func threeSum(nums []int) (res [][]int) {
	n := len(nums)
	sort.Ints(nums)
	pre := -1000000
	for i, x := range nums { // x is the 1st int in [x, y, z]
		if x == pre {
			continue
		}
		if x > 0 {
			break
		}
		if x+nums[n-1]+nums[n-2] < 0 {
			continue
		}
		for l, r := i+1, len(nums)-1; l < r; {
			if nums[l]+nums[r] == -x { // good case
				res = append(res, []int{x, nums[l], nums[r]})
				p := nums[l]
				for l < r && nums[l] == p {
					l++
				}
				p = nums[r]
				for l < r && nums[r] == p {
					r--
				}
				continue
			}
			if nums[l]+nums[r] > -x {
				r--
				continue
			}
			if nums[l]+nums[r] < -x {
				l++
				continue
			}
		}
		pre = x
	}
	return res
}