// Go
// leetcode 825
// https://leetcode.cn/problems/friends-of-appropriate-ages/

func numFriendRequests(ages []int) (res int) {
	cnt := make([]int, 121)

	for _, v := range ages {
		cnt[v]++
	}

	for i := 15; i <= 120; i++ {
		if cnt[i] == 0 {
			continue
		}

		tmp := 0
		for j := i / 2 + 8; j <= i; j++ {
			tmp += cnt[j]
		}

		res += cnt[i] * (tmp - 1)
	}

	return res
}