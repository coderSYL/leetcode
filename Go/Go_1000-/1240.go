// Go
// leetcode 1240
// https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares/

func tilingRectangle(n int, m int) int {
	mat := make([]int, n)
	// mat[i] 表示第 i 行
	// (mat[i] >> j) == 1 表示 [i][j]已铺好
	setMatTrue := func(x, y, sz int) bool {
		// 0b000111111100
		//      x     	(x+sz)	index
		full := 0
		for k:=y; k<y+sz; k++ {
			full |= 1<<k
		}
		for i:=x; i<x+sz; i++ {
			if mat[i] & full != 0 {
				return false
			}
		}
		for i:=x; i<x+sz; i++ {
			mat[i] |= full
		}
		return true
	}

	setMatFalse := func(x, y, sz int) {
		full := 0
		for k:=y; k<y+sz; k++ {
			full |= 1<<k
		}
		full = ^full
		for i:=x; i<x+sz; i++ {
			mat[i] &= full
		}
	}

	res := estimate(m,n)
	curRectangleCnt := 0
	var dfs func(int, int) 
	dfs = func(x, y int) {
		// fmt.Println(x,y)
		if y == m {
			x, y = x+1, 0
		}
		if x == n {
			res = min(res, curRectangleCnt)
			return
		}

		if (mat[x]>>y &1) ==  1 {
			dfs(x, y+1)
			return
		}
        if curRectangleCnt >= res {
            return
        }
		curRectangleCnt++
		maxPossible := min(n-x, m-y)
		for sz:=1;sz<=maxPossible;sz++ {
			ok := setMatTrue(x,y, sz)
			if ok {
				dfs(x, y+sz)
			} else {
				break
			}
			setMatFalse(x,y,sz)
		}
		curRectangleCnt--
	}
	dfs(0,0)
	return res
}

func max(a, b int) int {
	if a > b {
		return a 
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func estimate(m, n int) int {
	if m < n {
		m, n = n, m
	}

	if n == 1 {
		return m
	}
    if n == 0 {
        return 0
    }
	return 1 + estimate(m-n, n)
}