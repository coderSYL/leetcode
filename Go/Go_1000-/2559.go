// Go
// leetcode 2559
// https://leetcode.cn/problems/count-vowel-strings-in-ranges/

func vowelStrings(words []string, queries [][]int) []int {
	n := len(words)
	prefixSum := make([]int, n+1)
	for i, s := range words {
		if isGoodWord(s) {
			prefixSum[i+1] = prefixSum[i] + 1
		} else {
			prefixSum[i+1] = prefixSum[i]
		}
	}
	
	m := len(queries)
	res := make([]int, m)
	for i:=0; i<m; i++ {
		res[i] = prefixSum[queries[i][1]+1] - prefixSum[queries[i][0]]
	}
	return res
}

func isGoodWord(s string) bool {
	return isVowel(s[0]) && isVowel(s[len(s)-1])
}

func isVowel(b byte) bool {
	return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u'
}