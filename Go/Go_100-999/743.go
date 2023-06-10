// Go
// leetcode 743
// https://leetcode.cn/problems/network-delay-time/

func networkDelayTime(times [][]int, n int, k int) int {
	// 邻接矩阵法
	mat := make([][]int, n)
	FAR := 1000_000
	for i := 0; i <n; i++ {
		mat[i] = make([]int, n)
		for j:=0; j < n; j++ {
			mat[i][j] = FAR
		}
	}

	for i:=0; i<len(times); i++ {
		a, b, c := times[i][0]-1, times[i][1]-1, times[i][2]
		mat[a][b] = c
	}

	vis := make([]bool, n)
	dis := make([]int, n)
	for i:=0; i<n; i++ {
		dis[i] = FAR
	}

	dis[k-1] = 0
	got := 0
	for got < n {
		goodIdx:= -1
		for i:=0; i<n; i++ {
			if vis[i] || dis[i] == FAR {
				continue
			}
			if goodIdx == -1 {
				goodIdx = i
			} else if dis[i] < dis[goodIdx] {
				goodIdx = i
			}
		}
		if goodIdx == -1 { // 无法到达更多结点
			return -1
		}
		vis[goodIdx] = true
		got++
		if got == n {
			return dis[goodIdx]
		}
		for i:=0; i<n; i++ {
			if vis[i] || mat[goodIdx][i] == FAR {
				continue
			}
			dis[i] = min(dis[i], dis[goodIdx] + mat[goodIdx][i])
		}
	}
	return -2 // never
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}