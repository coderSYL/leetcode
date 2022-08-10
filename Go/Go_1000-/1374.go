// Go
// leetcode 1374
// https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/

func generateTheString(n int) string {
	tmp := make([]byte, n)
	for i := 1; i < n; i++ {
		tmp[i] = 'a'
	}
	if n&1 == 1 {
		tmp[0] = 'a'
	} else {
		tmp[0] = 'b'
	}

	return string(tmp)
}