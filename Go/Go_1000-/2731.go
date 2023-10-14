// Go
// leetcode 2731
// https://leetcode.cn/problems/movement-of-robots/

func sumDistance(nums []int, s string, d int) int {
	mod := 1000_000_007
	for i, pos := range nums { // 算出每个机器人的最终位置
		dir := -1
		if s[i] == 'R' {
			dir = 1
		}
		cur := pos + dir * d
		nums[i] = cur
	}
	sort.Ints(nums) // 按坐标排序

	res := 0
	sum := 0
	for i, p := range nums { // 计算距离
		res = (res - sum + i * p) % mod
		sum += p
	}
	
	return res
}