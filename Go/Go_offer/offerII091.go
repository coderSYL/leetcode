// Go
// leetcode offerII 091
// https://leetcode.cn/problems/JEj789/

func minCost(cs [][]int) int {
	n, res := len(cs), 30000
	
	// dp
	for i := 1; i < n; i++ {
		for j := 0; j < 3; j++ {
			cur := 30000
			for k := 0; k < 3; k++ {
				if j == k {
					continue
				}
				if now := cs[i][j] + cs[i-1][k]; now < cur {
					cur = now
				}
			}
			cs[i][j] = cur
		}
	}

	// collecting answer from row n-1 
	for i := 0; i < 3; i++ {
		if cs[n-1][i] < res {
			res = cs[n-1][i]
		}
	}
	return res
}