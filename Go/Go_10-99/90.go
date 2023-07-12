// Go
// leetcode 90
// https://leetcode.cn/problems/subsets-ii/

func subsetsWithDup(nums []int) [][]int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	arr := []int{}
	for i, _ := range cnt {
		arr = append(arr, i)
	}
	res := make([][]int, 0, 4)
    res = append(res, []int{})
	n := len(arr)
	full := (1<<n)-1
	var dfs func([]int, int, int)
	dfs = func(cur []int, idx,u int) {
		if idx == n {
			res = append(res, getCopy(cur))
			return
		}
		if u>>idx & 1 == 0 {
			dfs(cur, idx+1, u)
			return
		}
		val := arr[idx]
		for i:=0; i<cnt[val]; i++ {
			cur = append(cur, val)
			dfs(cur, idx+1, u)
		}
		cur = cur[:len(cur) - cnt[val]]
	}
	cur := []int{}
	for i:= full; i > 0; i = (i-1) & full {
		dfs(cur, 0, i)
	}
	return res
}

func getCopy(arr []int) []int {
	res := make([]int, len(arr))
	for i, x :=range arr {
		res[i] = x
	}
	return res
}