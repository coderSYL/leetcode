// Go
// leetcode 1761
// https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph/

func minTrioDegree(n int, edges [][]int) int {
	deg := make([]int, n)
	sorted := make([]int, n)
	exist := make(map[int]bool, len(edges))
	regist := func(a, b int) {
		if a > b {
			a, b = b, a
		}
		x := a*500 + b
		exist[x] = true
	}

	check := func(a,b int) bool {
		if a > b {
			a, b = b, a
		}
		x := a*500 + b
		_, ok := exist[x]
		return ok
	}

	for _, p := range edges {
		a, b := p[0]-1, p[1]-1
		if a>b {
			a, b = b, a
		}
		deg[a]++
		deg[b]++
		regist(a, b)
	}

	for i := range sorted {
		sorted[i] = i
	}

	sort.Slice(sorted, func(i, j int) bool {
		a, b := sorted[i], sorted[j]
		return deg[a] <= deg[b]
	})
	res := 1000_000

	for i:=2; i<n; i++ {
		x := sorted[i]
		if res + 2 <= deg[x] {
			break
		}
		for j:=0; j<i; j++ {
			y := sorted[j]
			// out condition
			if deg[x] + deg[y] - 4 >= res  {
				break
			}

			if !check(x, y) {
				continue
			}
			for k := j+1; k<i; k++ {
				z := sorted[k]
				if deg[x] + deg[y] + deg[z] - 6 >= res {
					break
				}
				if check(x, z) && check(y, z) {
					res = min(res, deg[x] + deg[y] + deg[z]-6)
				}
			}
		}
	}

	if res == 1000_000 {
		return -1
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}