// Go
// leetcode 1010
// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/

func numPairsDivisibleBy60(time []int) int {
	cnt := make([]int, 60)
	for _, timeForASong := range time {
		cnt[timeForASong%60]++
	}
	res := (cnt[0]-1)*cnt[0]/2 + (cnt[30]-1)*cnt[30]/2
	for i := 1; i < 30; i++ {
		res += cnt[i] * cnt[60-i]
	}
	return res
}