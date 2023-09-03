// Go
// leetcode 833
// https://leetcode.cn/problems/find-and-replace-in-string/

import "sort"

func findReplaceString(s string, indices []int, sources []string, targets []string) string {
	m := len(indices)
	arr := make([]int, m)
	for i := range arr {
		arr[i] = i
	}
	sort.Slice(arr, func(i, j int) bool {
		a, b := arr[i], arr[j]
		return indices[a] < indices[b]
	})
	n := len(s)
	diff := 0
	goodIndices := []int{}
	op := func(x int) {
		startPlace := indices[x]
		if startPlace + len(sources[x]) > n { // 超了
			return
		}
		for i:=0;i<len(sources[x]); i++ {
			if s[startPlace+i] != sources[x][i] { // 不一致
				return
			}
		}
		goodIndices = append(goodIndices, x)
		diff += len(targets[x]) - len(sources[x])
	}

	for _, x := range arr {
		op(x)
	}
	if len(goodIndices) == 0 {
		return s
	}
	k := n+diff
	tmp := make([]byte, k)
	p :=0
	
	for i,j:=0, 0; i<k; { // i for tmp, j for s
		if j == indices[goodIndices[p]] {
			x := goodIndices[p]
			j += len(sources[x])
			for idx, r := range targets[x] {
				tmp[i+idx] = byte(r)
			}
			i+= len(targets[x])
			p++ 
			if p == len(goodIndices) {
				for i<k {
					tmp[i] = s[j]
					i++
					j++
				}
			}
			continue
		}
		tmp[i]=s[j]
		i++
		j++
	}
	return string(tmp)
}