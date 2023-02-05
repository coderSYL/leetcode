// Go
// leetcode 873
// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/

func lenLongestFibSubseq(arr []int) int {
	n, getIdx := len(arr), map[int]int{}
	f := make([][]int, n)
	for i, v := range arr {
		getIdx[v] = i
		f[i] = make([]int, n)
	}
	res := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if k, ok := getIdx[arr[i]+arr[j]]; ok {
				if f[i][j] == 0 {
					f[j][k] = 3
				} else {
					f[j][k] = f[i][j] + 1
				}
				res = max(res, f[j][k])
			}
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}