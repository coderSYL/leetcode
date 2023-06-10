// Go
// leetcode 2611
// https://leetcode.cn/problems/mice-and-cheese/

func miceAndCheese(reward1 []int, reward2 []int, k int) int {
	sum := 0
	n := len(reward1)
	for i:=0; i<n; i++ {
		reward1[i] -= reward2[i]
		sum += reward2[i]
	}
	sort.Ints(reward1)
	for ; k > 0; k-- {
		sum += reward1[n-k]
	}
	return sum
}