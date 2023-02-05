// Go
// leetcode 2391
// https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/

func garbageCollection(garbage []string, travel []int) (res int) {
	var getIdx = map[byte]int{'M': 0, 'P': 1, 'G': 2}
	n := len(garbage)
	cnt := make([][]int, 3)
	end := make([]int, 3)
	for i := 0; i < 3; i++ {
		cnt[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < len(garbage[i]); j++ {
			cnt[getIdx[garbage[i][j]]][i]++
		}
		for j := 0; j < 3; j++ {
			if cnt[j][i] != 0 {
				end[j] = i
			}
		}
	}

	for i := 0; i < 3; i++ {
		// 每次计算一种垃圾耗时
		res += cnt[i][0]
		for j := 1; j <= end[i]; j++ {
			res += cnt[i][j] + travel[j-1]
		}
	}

	return res
}