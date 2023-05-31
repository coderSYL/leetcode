// Go
// leetcode 2451
// https://leetcode.cn/problems/odd-string-difference/

func oddString(words []string) string {
	idx := map[string]int{}
	for i := 0; i < len(words); i++ {
		n := len(words[i])
		arr := make([]byte, n-1)
		for j := 0; j < n-1; j++ {
			arr[j] = words[i][j+1] - words[i][j] + 64
		}

		s := string(arr)

		maybe, ok := idx[s]
		// fmt.Println(arr)
		if ok && maybe == -1 {
			continue
		} else if ok {
			idx[s] = -1
			if len(idx) == 2 {
				break
			}
		} else {
			idx[s] = i
		}
	}
	for _, i := range idx {
		if i >= 0 {
			return words[i]
		}
	}
	return "something wrong" // never
}