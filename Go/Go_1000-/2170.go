// Go
// leetcode 2170
// https://leetcode.cn/problems/minimum-operations-to-make-the-array-alternating/

func minimumOperations(nums []int) int {
	var cnt [2][100009]int
	var p [2][2]int
	var u int
	for i, v := range nums {
		u = 1 & i
		cnt[u][v]++
		if p[u][0] == v {
			continue
		}

		if cnt[u][v] > cnt[u][p[u][0]] {
			p[u][1] = p[u][0]
			p[u][0] = v
		} else if cnt[u][v] > cnt[u][p[u][1]] {
			p[u][1] = v
		}
	}

	if p[0][0] == p[1][0] {
		return len(nums) - maxOf2(cnt[0][p[0][0]]+cnt[1][p[1][1]], cnt[0][p[0][1]]+cnt[1][p[1][0]])
	}

	return len(nums) - cnt[0][p[0][0]] - cnt[1][p[1][0]]
}

func maxOf2(a, b int) int {
	if a > b {
		return a
	}
	return b
}