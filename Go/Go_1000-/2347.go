// Go
// leetcode 2347
// https://leetcode.cn/problems/best-poker-hand/

func bestHand(ranks []int, suits []byte) string {
	if suits[0] == suits[1] &&
		suits[0] == suits[2] &&
		suits[0] == suits[3] &&
		suits[0] == suits[4] { // 同花
		return "Flush"
	}
	cnt := make([]int, 14)
	for _, r := range ranks {
		cnt[r]++
	}
	for i := 1; i <= 13; i++ {
		cnt[0] = max(cnt[0], cnt[i])
	}
	if cnt[0] >= 3 {
		return "Three of a Kind"
	} else if cnt[0] == 2 {
		return "Pair"
	}

	return "High Card"
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}