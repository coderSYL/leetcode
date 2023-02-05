// Go
// leetcode 875
// https://leetcode.cn/problems/koko-eating-bananas/

func minEatingSpeed(piles []int, h int) int {
	m := 0
	for _, v := range piles {
		if v > m {
			m = v
		}
	}
	l, r := 1, m
	for l <= r {
		mid := (l + r + 1) >> 1
		if get_h(&piles, mid) <= h {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return l
}

func get_h(p *[]int, k int) int {
	res := 0
	for _, v := range *p {
		res += v / k
		if v%k != 0 {
			res++
		}
	}
	return res
}