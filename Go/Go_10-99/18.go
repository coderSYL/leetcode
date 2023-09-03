// Go
// leetcode 18
// https://leetcode.cn/problems/4sum/

func fourSum(nums []int, target int) (res [][]int) {
	sort.Ints(nums)
	n := len(nums)
    // fmt.Println(nums)
	for i:=0; i< n;{
		for j:=i+1; j <n ;  {
            // fmt.Println(i, j)
			l, r := j+1, n-1
			for l<r {
				cur := nums[i] + nums[j] + nums[l] + nums[r]
				if cur == target {
                    // fmt.Println("GET")
					res = append(res, []int{nums[i],nums[j], nums[l], nums[r]})
					oldL:= l
					for l < r && nums[l] == nums[oldL] {
						l++
					}
                    r--
				} else if cur < target {
					oldL := l
					for l < r && nums[l] == nums[oldL] {
						l++
					}
				} else {
					oldR := r
					for l < r && nums[r] == nums[oldR] {
						r--
					}
				}
			}

			nextJ := j
			for nextJ < n && nums[nextJ] == nums[j] {
				nextJ++
			}
			j = nextJ
		}

		nextI := i
		for nextI < n && nums[nextI] == nums[i] {
			nextI++
		}
		i = nextI
	}
	return res
}