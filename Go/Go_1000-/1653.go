// Go
// leetcode 1653
// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

func minimumDeletions(s string) int {
	n := len(s)
	cntA := make([]int, n+1) // 统计前 i 个字符中有几个 'a'
	for i, r := range s {
		if r == 'a' {
			cntA[i+1] = cntA[i] + 1
		} else {
			cntA[i+1] = cntA[i]
		}
	}

	res := n
	for i := 0; i <= n; i++ {
		// 前 i 个删成全 a，后面删成全 b
		leftPart := i - (cntA[i] - cntA[0])
		rightPart := cntA[n] - cntA[i]
		res = min(res, leftPart+rightPart)
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}