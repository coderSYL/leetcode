// Go
// leetcode 834
// https://leetcode.cn/problems/sum-of-distances-in-tree/


func sumOfDistancesInTree(n int, edges [][]int) []int {
	N, M := n, 2 * n
	idx := 1	// 初始值为1，因为在 go 中，切片会自动初始为零值，所以 id 为 0 的边应该不予记录数据
	he := make([]int, N) // 每个节点的第一个边的id
	e := make([]int, M)	// 第 i 条边指向哪个节点
	ne := make([]int, M) // 与第 i 条边同出发点的下一条边的id

	add := func(a, b int) {
		e[idx] = b // 边idx 指向 b
		ne[idx] = he[a] // 边idx 的下一条同源边是 结点a 的第一条边
		he[a] = idx // 边idx 取代了结点a 的第一条边，头插法
		idx++
	}
	for _, e := range edges {
		add(e[0], e[1])
		add(e[1], e[0])
	}

	// 遍历结点a 的所有边
	for i := he[a]; i != 0; i = ne[i] {
		b:= e[i]
		// do something
	}
	res := make([]int, n)
	for i:= 0; i <n; i++ {
		// 计算 i 到 j 的距离， 其中 j > i
		cnt := 0
		need := n-i
		queue := []int{i}
		vis := make([]bool, n)
		vis[i] = true
		dis := 0
		for len(queue) != 0 && cnt < need {
			dis++
			sz := len(queue)
			for j :=0; j <sz && cnt < need; j++ {
				a := queue[j]
				for k := he[a]; k != 0 && cnt < need; k = ne[k] {
					b:= e[k]
					if vis[b] {
						continue
					}
					vis[b] = true
					if b > i {
						cnt++
						res[i] += dis
						res[b] += dis
					}
					queue = append(queue, b)
				}
			}
			queue = queue[sz:]
		}
	}
	return res
}

