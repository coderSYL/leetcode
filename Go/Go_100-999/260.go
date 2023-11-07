// Go
// leetcode 260
// https://leetcode.cn/problems/single-number-iii/

func singleNumber(nums []int) []int {
	xor := 0
	res := []int{0,0}
	for _, x := range nums {
		xor ^= x
	}
	k := 33
	for i:=32; i>=0 && k > 32; i-- {
		if (xor>>i) & 1 == 1 {
			k = i
		}
	}

	for _, x := range nums {
		u := ((x ^ xor)>>k)&1
		res[u] ^= x
	}
	return res
}