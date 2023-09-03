// Go
// leetcode 2682
// https://leetcode.cn/problems/find-the-losers-of-the-circular-game/

func circularGameLosers(n int, k int) []int {
	cnt := make([]int, n)
	cur := 0
	round := 1
	for {
		cnt[cur]++
		if cnt[cur] == 2 {
			break
		}
		cur = (cur + round * k) % n
		round++
	}

	losers := make([]int, 0, 50)
	for i, x := range cnt {
		if x == 0 {
			losers = append(losers, i+1)
		}
	}
	return losers
}