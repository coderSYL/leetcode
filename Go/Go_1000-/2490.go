// Go
// leetcode 2490
// https://leetcode.cn/problems/circular-sentence/

func isCircularSentence(sentence string) bool {
	n := len(sentence)
	if sentence[0] != sentence[n-1] {
		return false
	}

	for i, c := range sentence {
		if c == ' ' {
			if sentence[i-1] != sentence[i+1] {
				return false
			}
		}
	}
	return true
}