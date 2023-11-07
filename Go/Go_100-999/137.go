// Go
// leetcode 137
// https://leetcode.cn/problems/single-number-ii/

func singleNumber(nums []int) int {
	cnt := make([]int, 32)
	minusCnt := 0 // 负号计数器
	minCnt := 0 // INT_MIN 的计数器
	for _, x := range nums {
		if x == -(1<<31) { // INT_MIN
			minCnt++
			continue
		}

		if x < 0 { // 负变正
			x = -x
			minusCnt++
		}

		for i:=0; x > 0; i++ {
			if x&1 == 1 {
				cnt[i]++
			}
			x/=2
		}
	}

	if minCnt% 3 == 1 { // INT_MIN
		return -(1<<31)
	}

	res := 0
	for i:=0; i<32;i++ {
		if cnt[i]%3 == 1 {
			res |= 1<<i
		}
	}

	if minusCnt%3 == 1 {
		res = -res
	}
	
	return res
}