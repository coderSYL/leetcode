// Go
// leetcode 242
// https://leetcode.cn/problems/valid-anagram/

func isAnagram(s string, t string) bool {
	cnt := make([]int, 26)
	for _, c := range s {
		u := int(c-'a')
		cnt[u]++
	}

	for _, c := range t {
		u := int(c-'a')
		cnt[u]--
	}

	for i := 0; i<26; i++ {
		if cnt[i] != 0 {
			return false
		}
	}

	return true
}