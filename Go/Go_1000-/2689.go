// Go
// leetcode 2698
// https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/

func punishmentNumber(n int) (res int) {
	for i:=1; i<=n; i++ {
		if digitSumCheck(i) {
			res += i*i
		}
	}
	return res
}

func digitSumCheck(one int) bool {
	x:= one*one
	arr := make([]int, 0, 10)
	for x >0 {
		arr = append(arr, x%10)
		x /= 10
	}

	for i, j := 0, len(arr)-1; i<j; {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
	return dfs(0, 0, arr, one)
}

func dfs(u, sum int, arr []int, target int) bool {
	if u == len(arr) {
		return sum == target
	}

	if sum > target {
		return false
	}

	cur := 0
	for u < len(arr) {
		cur = cur * 10 + arr[u]
		u++
		if dfs(u, sum + cur, arr, target) {
			return true
		}
	}

	return false
}