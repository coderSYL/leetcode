// Go
// leetcode 1090
// https://leetcode.cn/problems/largest-values-from-labels/

func largestValsFromLabels(values []int, labels []int, numWanted int, useLimit int) (res int) {
	n := len(values)
	id := make([]int, n)
	for i := 1; i < n; i++ {
		id[i] = i
	}
	sort.Slice(id, func(i, j int) bool {
		return values[id[i]] > values[id[j]]
	})
	choose := 0
	cnt := make(map[int]int)
	for i := 0; i < n && choose < numWanted; i++ {

		label := labels[id[i]]
		if cnt[label] == useLimit {
			continue
		}
		choose++
		res += values[id[i]]
		cnt[label]++
	}
	return res
}