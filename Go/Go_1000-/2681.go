// Go
// leetcode 2681
// https://leetcode.cn/problems/power-of-heroes/

func sumOfPower(nums []int) int {
	sort.Ints(nums)
	MOD := 1000_000_007
	res := 0
	s := 0
	for _,x := range nums {
		res = (res + ((x*x) % MOD) * (s + x))%MOD
		s = ((2*s) + x) % MOD 
	}
	return res
}