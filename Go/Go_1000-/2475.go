// Go
// leetcode 2475
// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

func unequalTriplets(nums []int) int {
	cnt := make([]int, 1001)
	next := make([]int, 1001)
	for _,x := range nums {
		cnt[x]++
	}
	a := 1001
	for i:=1000; i >=0; i-- {
		if cnt[i] == 0 {
			continue
		} else {
			next[i] = a
			a = i
		}
	}
	res := 0
	for i:=a; i<=1000; i = next[i] {
		for j:=next[i]; j <= 1000; j = next[j] {
			for k:=next[j]; k<=1000; k = next[k] {
				res += cnt[i] *cnt[j] * cnt[k]
			}
		}
	}
	return res
}