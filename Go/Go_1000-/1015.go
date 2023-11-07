// C++
// leetcode 1015
// https://leetcode.cn/problems/smallest-integer-divisible-by-k/

func smallestRepunitDivByK(k int) int {
	res, left := 1, 1%k
	vis := make([]bool, k)
	for left != 0 {
		if vis[left] {
			return -1
		} else {
			vis[left] = true
		}
		res++
		left = (left*10 + 1) % k

	}
	return res
}