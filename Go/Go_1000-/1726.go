// Go
// leetcode 1726
// https://leetcode.cn/problems/tuple-with-same-product/

func tupleSameProduct(nums []int) int {
	cnt := make(map[int]int)
	ok := make([]int, 505)
	n:=len(nums)
	for i:=0; i<n; i++ {
		x := nums[i]
		for j:=i+1;j<n;j++ {
			cnt[x*nums[j]]++
			ok[cnt[x*nums[j]]]++
		}
	}
	
	cur := 0
	res := 0
	
	for x:=500; x>0; x-- {
		ok[x] -= cur
		cur += ok[x]
		res += (x-1) * x * ok[x] * 4
	}
	return res
}