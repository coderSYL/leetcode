// Go
// leetcode 2605
// https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/

func minNumber(nums1 []int, nums2 []int) int {
	a, b := 10, 10
	cnt := make([]int, 10)
	for _, x := range nums1 {
		a = min(a, x)
		cnt[x] = 1
	}
	for _, x := range nums2 {
		b = min(b, x)
		cnt[x] |= 2
	}
	for i:=1; i<10; i++ {
		if cnt[i] == 3 {
			return i
		}
	}
	if a > b {
		a, b= b, a
	}
	return a * 10 + b
}

func findMin(arr []int) int {
	res := 10000000000
	for _,x := range arr {
		res = min(res, x)
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}