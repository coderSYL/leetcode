// Go
// leetcode 667
// https://leetcode.cn/problems/beautiful-arrangement-ii/

func constructArray(n int, k int) []int {
	k--
	up, down, times := 1, n, k >> 1

	res := make([]int, n)
	for i := 0; i < n; i++ {
		if i%2 == 1 && times > 0 {
			times--
			res[i] = down
			down--
		} else {
			res[i] = up
			up++
		}
	}
	
	if (k % 2 == 1) {
		res[n-1], res[n-2] = res[n-2], res[n-1]
	}
	return res
}