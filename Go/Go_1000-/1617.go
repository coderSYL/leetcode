// Go
// leetcode 1617
// https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/

func countSubgraphsForEachDiameter(n int, edges [][]int) []int {
	res := make([]int, n-1)
	g := make([][]int, n)
	for _, e := range edges { // 建图
		x, y := e[0]-1, e[1]-1
        // fmt.Println(x, y)
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	for mask := 3; mask < 1<<n; mask++ {
		if mask & (mask-1) == 0 { // 只有一个点，不行
			continue
		}
		
		vis, diameter := 0, 0
		var dfs func(int) int
        dfs = func(x int) (maxLen int) {
            vis |= 1 << x // 标记 x 访问过
            for _, y := range g[x] {
                if vis>>y&1 == 0 && mask>>y&1 > 0 { // y 没有访问过且在 mask 中
                    ml := dfs(y) + 1
                    diameter = max(diameter, maxLen+ml)
                    maxLen = max(maxLen, ml)
                }
            }
            return
        }
        dfs(helper(mask)) // 从一个在 mask 中的点开始递归
        if vis == mask {
            res[diameter-1]++
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

func helper(x int) (res int) { // 返回最低位的idx，最右边从0开始
	y := x & -x
    for y > 1 {
        y >>= 1
        res++
    }
    return res
}