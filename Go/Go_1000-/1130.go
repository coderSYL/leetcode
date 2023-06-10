// Go
// leetcode 1130
// https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values/

func mctFromLeafValues(arr []int) (res int) {
	n := len(arr)
	memo := make([][]int, n)
	for i:=0; i<n; i++ {
		memo[i] = make([]int, n)
	}
	
	big := make([][]int, n)
	for i:=0; i<n; i++ {
		big[i] = make([]int, n)
	}

	var getBig func(int, int) int
	getBig = func(l, r int)  int {
		if big[l][r] != 0 {
			return big[l][r]
		}
		
		if l==r {
			big[l][r] = arr[l]
			return big[l][r]
		}
		big[l][r] =  max(getBig(l, r-1), arr[r])
		return big[l][r]
	}

	var dfs func(int, int) int
	dfs = func(l, r int)  int {
		if l == r {
			return 0
		}

		if memo[l][r] != 0 {
			return memo[l][r]
		}

		res := 1<<30 + 1<<29

		for x := l; x < r; x++ {
			cur := getBig(l, x) * getBig(x+1, r)
			cur += dfs(l, x) + dfs(x+1, r)
			res = min(res, cur)
		}
		memo[l][r] = res
		return res
	}
	return dfs(0, n-1)
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