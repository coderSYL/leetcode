// Go
// leetcode 697
// https://leetcode.cn/problems/degree-of-an-array/

func findShortestSubArray(nums []int) int {
	cnt := make([]int, 50009)
	first := make([]int, 50009)
	last := make([]int, 50009)
	mx := 0
	candidates := make([]int, 0, 4)
	for i, x := range nums {
		cnt[x]++
		if cnt[x] == 1 {
			first[x] = i
		}

		if cnt[x] > mx {
			mx = cnt[x]
			candidates = candidates[0:0]
		}

		if cnt[x] == mx {
			candidates = append(candidates, x)
		}

		last[x] = i
	}
	res := 99999
	// fmt.Println(mx)
	for _, x := range candidates {
		res = min(res, last[x]-first[x]+1)
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}