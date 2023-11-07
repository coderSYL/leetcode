// Go
// leetcode 2586
// https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/

func vowelStrings(words []string, left int, right int) int {
	res := 0
	for i:=left; i<=right; i++ {
		if isGoodWord(words[i]) {
			res++
		}
	}
	return res
}

func isGoodWord(s string) bool {
	return isVowel(s[0]) && isVowel(s[len(s)-1])
}
func isVowel(b byte) bool {
	return b=='a' || b=='e' || b=='i' || b=='o' || b=='u'
}