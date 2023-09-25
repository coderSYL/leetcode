// Go
// leetcode 2603
// https://leetcode.cn/problems/collect-coins-in-a-tree/

func collectTheCoins(coins []int, edges [][]int) int {
	n := len(coins)
	g := make([][]int, n)
	deg := make([]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		deg[a]++
		deg[b]++
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	q := []int{}
	for i:= 0; i< n; i++{
		if deg[i] == 1 && coins[i] == 0 {
			q = append(q, i)
		}
	}

	leftEdges := n-1

	// 删无金币的叶子结点
	for len(q) > 0 {
		sz := len(q)
		x := q[sz-1]
		q = q[:sz-1]
		leftEdges--
		for _, y := range g[x] {
			deg[y]--
			if deg[y] == 1 && coins[y] == 0 {
				q = append(q, y)
			}
		}
	}

	for i, d := range deg {
		if d == 1 && coins[i] > 0 {
			q = append(q, i)
		}
	}

	leftEdges -= len(q)

	for _, x := range q {
		for _, y := range g[x] {
			deg[y]--
			if deg[y] == 1 {
				leftEdges--
			}
		}
	}
	
	if leftEdges > 0 {
		return 2 * leftEdges
	}
	return 0
}