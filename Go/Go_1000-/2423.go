// Go
// leetcode 2423
// https://leetcode.cn/problems/remove-letter-to-equalize-frequency/

func equalFrequency(word string) bool {
	cnt := make([]int, 26)
	for _, c := range word {
		u := int(c - 'a')
		cnt[u]++
	}
	frequency := make(map[int]int)
	for _, x := range cnt {
		if x == 0 {
			continue
		}
		frequency[x]++
	}
	switch len(frequency) {
	case 1:
		if _, ok := frequency[1]; ok {
			return true
		} else {
			for _, v := range frequency {
				if v == 1 {
					return true
				}
			}
			return false
		}
	case 2:
		one, ok := frequency[1]
		if ok && one == 1 {
			return true
		}
		maxF := 0
		for f, _ := range frequency {
			maxF = max(maxF, f)
		}
		_, ok = frequency[maxF-1]
		if frequency[maxF] == 1 && ok {
			return true
		}
		return false
	default:
		return false
	}
	return false
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}