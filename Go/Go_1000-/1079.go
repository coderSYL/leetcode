// Go
// leetcode 1079
// https://leetcode.cn/problems/letter-tile-possibilities/

func numTilePossibilities(tiles string) (res int) {
	cnt := make([]int, 26)
	for _, c := range tiles { // 统计各个字母的个数
		cnt[c-'A']++
	}

	// 去掉个数为 0 的字母
	sort.Ints(cnt)
	i := 0
	for cnt[i] == 0 {
		i++
	}
	cnt = cnt[i:]

	tmp := make([]int, len(cnt))
	var helper func(cur, remain int) // dfs helper function
	helper = func(cur, remain int) {
		if remain == 0 { // 无剩余，可结算
			res += getNum(tmp)
			return
		}
		if cur == len(cnt) { // 可选种类已穷尽
			return
		}
		maxPossible := min(remain, cnt[cur])
		for taken := maxPossible; taken >= 0; taken-- { // dfs，从大到小以确保最终 tmp切片为0
			tmp[cur] = taken
			helper(cur+1, remain-taken)
		}
		return
	}

	for size := 1; size <= len(tiles); size++ {
		// n 个字符中选出 size 个
		helper(0, size)
	}

	return res
}

func getNum(arr []int) int {
	sum := 0
	down := 1
	for _, x := range arr {
		sum += x
		down *= fac(x)
	}
	return fac(sum) / down
}

func fac(a int) (res int) {
	res = 1
	for a > 1 {
		res *= a
		a--
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}