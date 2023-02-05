// Go
// leetcode offerII034
// https://leetcode.cn/problems/lwyVBB/

func isAlienSorted(words []string, order string) bool {
	getIdx := make([]int, 26)
	for i, c := range order {
		getIdx[int(c-'a')] = i
	}

	n := len(words) - 1

	for i := 0; i < n; i++ {
		if !check(words[i], words[i+1], getIdx) {
			return false
		}
	}

	return true
}

// judge if s1 <= s2 in getIdx order
func check(s1, s2 string, getIdx []int) bool {
	n1, n2, n := len(s1), len(s2), len(s1)
	if n2 < n {
		n = n2
	}

	for i := 0; i < n; i++ {
		u1, u2 := getIdx[int(s1[i]-'a')], getIdx[int(s2[i]-'a')]
		if u1 < u2 {
			return true
		} else if u1 > u2 {
			return false
		}
	}

	return n1 <= n2
}