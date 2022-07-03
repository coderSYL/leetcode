// Go
// leetcode 30
// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

func findSubstring(s string, words []string) []int {
	n, wordNum, wordLength:= len(s), len(words), len(words[0])
	res := make([]int, 0, 5)

	// 
	need := make(map[string]int, wordNum)
	for _, word := range words {
		need[word]++
	}

	// working
	for i := 0; i < wordLength && i < n; i++ {
		l, r, cnt := i, i, 0
		cur := make(map[string]int)
		for r + wordLength <= n {
			curWord := s[r : r + wordLength]
			r += wordLength

			curNeed, ok := need[curWord]
			if ok {
				// need curWord
				cur[curWord]++
				cnt++

				for cur[curWord] > curNeed {
					toBeDelete := s[l : l + wordLength]
					l += wordLength
					cur[toBeDelete]--
					cnt--
				}

				if cnt == wordNum {
					res = append(res, l)
				}
			} else {
				// don't need curWord
				l = r
				cnt = 0
				cur = make(map[string]int)
				if l + wordNum * wordLength > n {
					continue
				}
			}
		}
	}
	return res
}