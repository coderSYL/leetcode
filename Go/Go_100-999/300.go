// Go
// leetcode 300
// https://leetcode.cn/problems/longest-increasing-subsequence/

func lengthOfLIS(nums []int) int {
	n := len(nums)
	smallestValForLength := make([]int, n)
	for i := 0; i < n; i++ {
		smallestValForLength[i] = 20000
	}
	for i, x := range nums {
		for j := i-1; j >= 0; j-- {
			if x > smallestValForLength[j] {
				smallestValForLength[j+1] = min(smallestValForLength[j+1], x)
			}
		}
        smallestValForLength[0] = min(smallestValForLength[0], x)
	}
    // fmt.Println(smallestValForLength)
	for i := n-1; i >= 0; i-- {
		if smallestValForLength[i] < 20000 {
			return i+1
		}
	}
	return 0
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}