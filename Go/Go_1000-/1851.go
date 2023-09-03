// Go
// leetcode 1851
// https://leetcode.cn/problems/minimum-interval-to-include-each-query/

func minInterval(intervals [][]int, queries []int) []int {
	sort.Slice(intervals, func(i, j int) bool { // 长度小的区间在前
		a, b := intervals[i], intervals[j]
		return a[1] - a[0] < b[1] - b[0]
	})

	n := len(queries)
	type pair struct {
		pos, i int
	}
	qs := make([]pair, n)
	for i, q := range queries {
		qs[i] = pair{q, i}
	}
	sort.Slice(qs, func(i, j int) bool {
		return qs[i].pos < qs[j].pos
	})

	f := make([]int, n+1)
	for i := range f {
		f[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if f[x] != x {
			f[x] = find(f[x])
		}
		return f[x]
	}

	res := make([]int, n)
    for i:= range res {
        res[i] = -1
    }
	for _, p := range intervals {
		l, r := p[0], p[1]
		length := r - l + 1
		i := sort.Search(n, func(x int) bool {
			return qs[x].pos >= l
		})
		for i:= find(i); i < n && qs[i].pos <= r; i = find(i+1){
			res[qs[i].i] = length
			f[i] = i+1
		}
	}
	return res
}