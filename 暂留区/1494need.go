// Go
// leetcode 1494
// https://leetcode.cn/problems/parallel-courses-ii/

func minNumberOfSemesters(n int, relations [][]int, k int) int {
	need := make([]int, n)
	for _, pair := range relations {
		before, after := pair[0]-1, pair[1]-1
		need[after] = need[after] | (1 << before)
	}

	full := (1 << n) - 1
	dp := make([]int, 1<<n)

	var dfs func(int) int
	dfs = func(x int) int { // 二进制形式下的 x 某位如果为 1，代表该课程还未上
		if x == 0 { // 课已经上完
			return 0
		}

		if dp[x] != 0 {
			return dp[x]
		}

		dp[x] = 16
		options := 0
		for i := 0; i < n; i++ {
			if (x>>i)&1 == 0 { // 该课已上
				continue
			}
			if qualified(need[i], x) {
				options |= 1 << i
			}
		}
		fmt.Printf("%b can have %b", x, options)
		if countOne(options) <= k { // 可上的课程少于 k 门，全上
			fmt.Println(" ALL")
			dp[x] = dfs(x & ^options) + 1
			return dp[x]
		}

		fmt.Println(" SOME")
		arr := getArr(options, k)
		fmt.Println(len(arr))
		for _, y := range arr {
			dp[x] = min(dp[x], dfs(x & ^y)+1)
		}
		return dp[x]
	}
	return dfs(full)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func countOne(x int) int {
	res := 0
	for x > 0 {
		res += x % 2
		x /= 2
	}
	return res
}

func qualified(need, curState int) bool { // true 代表可上
	return need&curState == 0
}

func getArr(x, k int) (res []int) {
	arr := []int{}
	for i := 0; i < 16; i++ {
		if (x>>i)&1 == 1 {
			arr = append(arr, i)
		}
	}
	q := []int{0} // take<<24 + i<<16 + cur
	for len(q) != 0 {

	}
	return res
}

func lowBit(x int) int {
	return x & -x
}