// Go
// leetcode 1462
// https://leetcode.cn/problems/course-schedule-iv/

func checkIfPrerequisite(numCourses int, prerequisites [][]int, queries [][]int) []bool {
	// 图的结构
	N, M := numCourses, len(prerequisites)
	idx := 1	// 初始值为1，因为在 go 中，切片会自动初始为零值，所以 id 为 0 的边应该不予记录数据
	he := make([]int, N) // 每个节点的第一个边的id
	e := make([]int, M+5)	// 第 i 条边指向哪个节点
	ne := make([]int, M+5) // 与第 i 条边同出发点的下一条边的id
	add := func(a, b int) { // a 是 b 的先修课程
		e[idx] = b // 边idx 指向 b
		ne[idx] = he[a] // 边idx 的下一条同源边是 结点a 的第一条边
		he[a] = idx // 边idx 取代了结点a 的第一条边，头插法
		idx++
	}

	for _, p := range prerequisites { // 边录入
		after, pre := p[0], p[1]
		add(pre, after)
	}

	// 记忆化
	vis := make([][]bool, N)
	memo := make([][]bool, N)
	for i:=0; i<N; i++ {
		vis[i] = make([]bool, N)
		memo[i] = make([]bool, N)
	}

	var preCourseCheck func(int, int) bool // a 是否是 b 的先决课程， dfs
	preCourseCheck = func(a, b int) bool { 
		if vis[a][b] {
			return memo[a][b]
		}
		vis[a][b] = true
		for i := he[a]; i != 0; i = ne[i] {
			next:= e[i]
			if next == b || preCourseCheck(next, b) {
				memo[a][b] = true
				return true
			}
		}
		return false
	}
	

	m := len(queries)
	res := make([]bool, m)
	for i:=0; i<m; i++ {
		res[i] = preCourseCheck(queries[i][1], queries[i][0])
	}
	return res
}