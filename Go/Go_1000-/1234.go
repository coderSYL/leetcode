// Go
// leetcode 1234
// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func balancedString(s string) int {
	cnt, m := ['X']int{}, len(s)/4
	for _, c := range s {
		cnt[c]++
	}
	if cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m {
		return 0
	}
	res, left := len(s), 0
	for right, c := range s {
		cnt[c]--
		for cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m {
			res = min(res, right-left+1)
			cnt[s[left]]++
			left++
		}
	}
	return res
}