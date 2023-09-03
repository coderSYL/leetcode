// Go
// leetcode 2050
// https://leetcode.cn/problems/parallel-courses-iii/

func minimumTime(n int, relations [][]int, time []int) int {
	N, M := n, len(relations) + 5
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

	preNum := make([]int, n)
	// 建图
	for _, p := range relations {
		pre, next := p[0]-1, p[1]-1
		add(pre, next)
		preNum[next]++
	}

	q := []int{}
	for i:=0; i<n; i++ {
		if preNum[i] == 0 {
			q = append(q, i)
		}
	}
	f := make([]int, n)
	res := 0
	for len(q) != 0 {
		m := len(q)
		x := q[m-1]
		q = q[:m-1]
		f[x] += time[x]
		res = max(res, f[x])
		for i := he[x]; i != 0; i = ne[i] {
			b := e[i]
			f[b] = max(f[b], f[x])
			preNum[b]--
			if preNum[b] == 0 {
				q = append(q, b)
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