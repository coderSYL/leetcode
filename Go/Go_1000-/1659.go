// Go
// leetcode 1659
// https://leetcode.cn/problems/maximize-grid-happiness/

func getMaxGridHappiness(m int, n int, introvertsCount int, extrovertsCount int) int {
	if m > n {
		m, n = n, m
	}
	memo := make(map[int]int)
	// preState 0-9 in 10-14 ex 15-19 line 20
	g := make(map[int]int)
	getTwo := func(pre, cur int) int {
		full := pre<<10 + cur
		tmp, ok := g[full]
		if ok {
			return tmp
		}
		score := 0
		left := 0
		arr := getArr(cur, n)
		upArr := getArr(pre, n)
		for i:=0; i<n; i++ {
			switch arr[i] {
			case 1:
				score += 120
			case 2:
				score += 40
			}
			score += getBonus(arr[i], upArr[i]) + getBonus(arr[i], left)
			left = arr[i]
		}
		g[full] = score
		return score
	}

	var dfs func(int, int, int, int) int
	dfs = func(in, ex, preState, line int) int {
		if (in == 0 && ex == 0) || line == m { // end condition
			return 0
		}
		
		code := getFullCode(in,ex,preState,line)
		tmp, ok := memo[code]
		if ok {
			return tmp
		}
		end := power3(n)
		res := 0
		for i:=0; i<end; i++ {
			needIn, needEx := getInAndEx(i)
			if needIn > in || needEx > ex {
				continue
			}
			score := getTwo(preState, i) + dfs(in - needIn, ex- needEx, i, line+1)
			res = max(res, score)
		}
		memo[code] = res
		return res
	}
	
	return dfs(introvertsCount, extrovertsCount, 0, 0)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// func encode(arr []int) int {
// 	res := 0
// 	for i:=len(arr)-1; i >= 0; i-- {
// 		res = res * 3 + arr[i]
// 	}
// 	return res
// }

func getArr(x, size int) []int {
	arr := make([]int, size)
	for i:=0; i<size && x > 0; i++ {
		arr[i] = x%3
		x /= 3
	}
	return arr
}

func getBonus(v1, v2 int) int {
	arr := []int{0, -60, -10, 99, 40}
	return arr[v1 * v2]
}

func power3(x int) int {
	res := 1
	for x > 0 {
		x--
		res *= 3
	}
	return res
}

func getInAndEx(x int) (int, int) {
	in, ex := 0, 0
	for x > 0 {
		u:=x%3
		if u == 1 {
			in++
		}
		if u==2 {
			ex++
		}
		x/=3
	}
	return in, ex
}

func getFullCode(in, ex, preState, line int) int {
	return preState + in<<10 + ex<<15 + line<<20
}