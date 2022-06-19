// Go
// leetcode 1
// https://leetcode.cn/problems/two-sum/

func twoSum(nums []int, target int) []int {
	n := len(nums)
	for i := 0; i < n; i++ {
		x := nums[i]
		for j := i+1; j < n; j++ {
			if x + nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{} // never
}

// faster using map
func twoSum(nums []int, target int) []int {
	n := len(nums)
	m := make(map[int]int, n)
	idx, ok := 0, false
	for i, v := range nums {
		idx, ok = m[target-v]
		if(ok) {
			return []int{idx, i}
		}
		m[v] = i
	}
	return []int{}
}