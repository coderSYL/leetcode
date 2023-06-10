// Go
// leetcode 2465
// https://leetcode.cn/problems/number-of-distinct-averages/

func distinctAverages(nums []int) int {
	cnt := make([]int,101)
	for _, x := range nums {
		cnt[x]++
	}
	sum := make(map[int]bool)
	for i, j:= 0, 100; i <= j; {
		for i<=j && cnt[i] == 0{
			i++
		}
		for i<=j && cnt[j] == 0 {
			j--
		}
		if i > j {
			break
		}
		cnt[i]--
		cnt[j]--
		sum[i+j] = true
	}
	return len(sum)
}