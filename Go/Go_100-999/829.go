// Go
// leetcode 829
// https://leetcode.cn/problems/consecutive-numbers-sum/

func consecutiveNumbersSum(n int) int {
	res, cur, sum := 0, 1, 1
	for sum <= n {
		if (n-sum)%cur == 0 {
			res++
		}
		cur++
		sum += cur
	}
	return res
}