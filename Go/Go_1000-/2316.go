// Go
// leetcode 2316
// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

func countPairs(n int, edges [][]int) (res int64) {
	vis := make([]bool, n)
	m := len(edges)

	// 图的组件
	idx := 1
	he := make([]int, n)
	e := make([]int, 2*m+5)
	ne := make([]int, 2*m+5)
	add := func(a, b int) {
		e[idx] = b
		ne[idx] = he[a]
		he[a] = idx
		idx++
	}

	// 图的录入
	for _, edge := range edges {
		a, b := edge[0], edge[1]
		add(a, b)
		add(b, a)
	}

	groups := []int{}
	for i:=0; i<n; i++ {
		if vis[i] {
			continue
		}
		cur := 1
		vis[i] = true
		q := []int{i}
		for len(q) != 0 {
			x := q[len(q)-1]
			q = q[:len(q)-1]
			for idx:=he[x]; idx!=0; idx = ne[idx] {
				b := e[idx]
				if vis[b] {
					continue
				}
				vis[b] = true
				q = append(q, b)
				cur++
			}
		}
		groups = append(groups, cur)
	}
	// fmt.Println(groups)
	for _, x :=range groups {
		res += int64(x * (n-x))
	}
	return res/2
}