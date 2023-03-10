// Go
// leetcode 982
// https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/

func countTriplets(nums []int) int {
	cnt := make([]int, 1<<16)
	for _, x := range nums {
		for _, y := range nums {
			cnt[x&y]++
		}
	}

	res := 0
	for _, z := range nums {
		z ^= (1 << 16) - 1
		s := z
		for {
			res += cnt[s]
			s = (s - 1) & z
			if s == z {
				break
			}
		}
	}

	return res
}