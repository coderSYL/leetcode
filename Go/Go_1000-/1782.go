// Go
// leetcode 1782
// https://leetcode.cn/problems/count-pairs-of-nodes/

func countPairs(n int, edges [][]int, queries []int) []int {
	deg := make([]int, n)
	cntE := make(map[int]int)
	for _, p := range edges {
		a, b := p[0]-1, p[1]-1
		if a > b {
			a, b = b, a
		}
		deg[a]++
		deg[b]++
		cntE[a*n + b] ++ 
	}

	res := make([]int, len(queries))
	sortedDeg := append(make([]int,0, n), deg...)
	sort.Ints(sortedDeg)

	for i, q := range queries {
		l, r := 0, n-1
		for l < r {
			if sortedDeg[l] + sortedDeg[r] <= q {
				l++
			} else {
				res[i] += r-l
				r--
			}
		}

		for e, c := range cntE {
			a, b := e/n, e%n
			s := deg[a] + deg[b]
			if s > q && s-c <= q {
				res[i]--
			}
		}
	}
	return res
}