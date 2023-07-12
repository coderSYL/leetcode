// Go
// leetcode 16
// https://leetcode.cn/problems/3sum-closest/

// dp
func threeSumClosest(nums []int, target int) int {
	f := make([][]bool, 3)
	for i:=0; i<3; i++ {
		f[i] = make([]bool, 6001)
	}
	for _, x := range nums {
		for i:=1000; i<=5000; i++ {
			if f[1][i] {
				f[2][i+x] = true
			}
		}

		for i:= 2000; i<=4000; i++ {
			if f[0][i] {
				f[1][i+x] = true
			}
		}
		
		f[0][x+3000] =true
	}

	if target > 3000 {
		for i:=6000; i >= 0; i-- {
			if f[2][i] {
				return i-3000
			}
		}
	}

	if target < -3000 {
		for i:=0; i <= 6000; i++ {
			if f[2][i] {
				return i-3000
			}
		}
	}
	u := target + 3000
	good := func(x int) bool {
		if x < 0 || x > 6000 {
			return false
		}
		return f[2][x]
	}

	for i:=0; i<=6000; i++ {
		if good(u+i) {
			return u+i -3000
		}
		if good(u-i) {
			return u-i -3000
		}
	}

	return 10000 // never
}


// // 双指针
// func threeSumClosest(nums []int, target int) int {
// 	sort.Ints(nums)

// 	res := nums[0]+nums[1]+nums[2]
// 	updateRes := func(x int) {
// 		diff := target - x
// 		if diff < 0 {
// 			diff = -diff
// 		}
// 		cur := target - res 
// 		if cur < 0 {
// 			cur = -cur
// 		}
// 		if diff < cur {
// 			res = x
// 		}
// 	}

// 	n := len(nums)
// 	for i:=0; i<n; i++ {
// 		firstNum := nums[i]
// 		l, r := i+1, n-1
// 		for l<r {
// 			cur := firstNum + nums[l] + nums[r]
// 			updateRes(cur)
// 			if cur > target {
// 				r--
// 			} else if cur <  target{
// 				l++
// 			} else {
// 				return target
// 			}
// 		}
// 	}
// 	return res
// }