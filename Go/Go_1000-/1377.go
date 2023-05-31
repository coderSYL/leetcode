// Go
// leetcode 1377
// https://leetcode.cn/problems/frog-position-after-t-seconds/

func frogPosition(n int, edges [][]int, t int, target int) float64 {
	cnt := make([]float64, n+1)
	vis := make([]bool, n+1)
	vis[1] = true

	ok := make([][]bool, n+1) // 邻接表
	for i := 1; i <= n; i++ {
		ok[i] = make([]bool, n+1)
	}

	for i := 0; i < len(edges); i++ { // 边的录入
		a, b := edges[i][0], edges[i][1]
		ok[a][b], ok[b][a] = true, true
	}

	var dfs func(int, int, float64)
	dfs = func(cur, secondLeft int, possibility float64) {
		if secondLeft == 0 { // 没步数了，结算
			cnt[cur] += possibility
			return
		}

		secondLeft--
		nextStep := []int{}
		for i := 1; i <= n; i++ {
			if ok[cur][i] && !vis[i] {
				nextStep = append(nextStep, i)
			}
		}

		if len(nextStep) == 0 {
			cnt[cur] += possibility
			return
		}

		possibility /= float64(len(nextStep))

		for _, next := range nextStep {
			vis[next] = true
			dfs(next, secondLeft, possibility)
			vis[next] = false
		}
	}

	dfs(1, t, 1.00000000)
	// fmt.Println(cnt)
	return cnt[target]
}