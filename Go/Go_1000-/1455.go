// Go
// leetcode 1455
// https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

func isPrefixOfWord(sentence string, word string) int {
	n, m, idx := len(sentence), len(word), 0
	for i := 0; i < n; i++ {
		idx++

		p := 0
		for p+i < n && p < m {
			if sentence[i+p] == word[p] {
				p++
			} else {
				break
			}
		}

		if p == m {
			return idx
		}

		i += p
		for i < n && sentence[i] != ' ' {
			i++
		}
	}

	return -1
}