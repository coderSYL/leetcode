// Go
// leetcode 2582
// https://leetcode.cn/problems/pass-the-pillow/

func passThePillow(n int, time int) int {
	round := 2*(n-1)
	time %= round
	if time < n {
		return time + 1
	}

	return 2 * n - time -1
}