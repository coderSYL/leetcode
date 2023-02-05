// Go
// leetcode 6
// https://leetcode.cn/problems/zigzag-conversion/

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	d, n, cur := 1, len(s), 0
	tmp := make([][]byte, numRows)
	for i := 0; i < n; i++ {
		tmp[cur] = append(tmp[cur], s[i])
		cur += d
		if cur == numRows {
			cur = numRows - 2
			d = -1
		} else if cur == -1 {
			cur = 1
			d = 1
		}
	}
	bs := make([]byte, 0, n)
	for i := 0; i < numRows; i++ {
		bs = append(bs, tmp[i]...)
	}
	return string(bs)
}