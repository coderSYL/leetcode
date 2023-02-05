// Go
// leetcode 1408
// https://leetcode.cn/problems/string-matching-in-an-array/

func stringMatching(ws []string) (res []string) {
	n := len(ws)

outer:
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// 不够长
			if len(ws[j]) <= len(ws[i]) {
				continue
			}

			// 判断是否匹配
			diff := len(ws[j]) - len(ws[i])
		inner:
			for k := 0; k <= diff; k++ {
				for p, v := range ws[i] {
					if byte(v) != ws[j][k+p] {
						continue inner
					}
				}
				res = append(res, ws[i])
				continue outer
			}
		}
	}

	return res
}