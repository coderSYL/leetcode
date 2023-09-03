// Go
// leetcode 1444
// https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/description/

func ways(pizza []string, k int) int {
	res := 0
	MOD := 1000_000_007

	// 统计苹果数量
	m, n := len(pizza), len(pizza[0])
	cnt := make([]int, m*n)
	for x, s := range pizza {
		for y, c := range s {
			if c == 'A' {
				for i:=0;i <= x; i++ {
					for j:=0; j<=y; j++ {
						cnt[i*n + j]++
					}
				}
			}
		}
	}

	dp := make([][]int, m*n)
	for i := range dp {
		dp[i] = make([]int, k)
	}
	dp[0][0] = 1

	for cut:=1; cut < k; cut++ {
		need := k-cut
		for idx := range dp {
			if cnt[idx] < need {
				continue
			}
			x, y := idx/n, idx%n
			for i:=0; i<=x; i++ {
				u := i*n+y
				if cnt[u] - cnt[idx] > 0 {
					dp[idx][cut] = (dp[idx][cut] + dp[u][cut-1]) % MOD
				}
			}
			for j:=0; j<= y; j++ {
				u := x*n+j
				if cnt[u] - cnt[idx] > 0 {
					dp[idx][cut] = (dp[idx][cut] + dp[u][cut-1]) % MOD
				}
			}
		}
	}

	for i:= range dp {
		if cnt[i] > 0 {
			res = (res + dp[i][k-1]) % MOD
		}
	}

	return res
}