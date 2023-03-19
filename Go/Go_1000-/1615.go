// Go
// leetcode 1615
// https://leetcode.cn/problems/maximal-network-rank/

func maximalNetworkRank(n int, roads [][]int) int {
	isConnected := make([][]bool, n)
	for i := 0; i < n; i++ {
		isConnected[i] = make([]bool, n)
	}
	cnt := make([]int, n)
	for _, r := range roads {
		x, y := r[0], r[1]
		cnt[x]++
		cnt[y]++
		isConnected[x][y] = true
		isConnected[y][x] = true
	}
	res := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			cur := cnt[i] + cnt[j]
			if isConnected[i][j] {
				cur--
			}
			res = max(res, cur)
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