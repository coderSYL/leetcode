// Go
// leetcode 2578
// https://leetcode.cn/problems/split-with-minimum-sum/

func splitNum(num int) int {
	cnt := []int{}
	for num > 0 {
		cnt = append(cnt, num%10)
		num /= 10
	}
	num1, num2 := 0, 0
	sort.Ints(cnt)
	for _, x := range cnt {
		if num1 <= num2 {
			num1 = num1 * 10 + x
			continue
		}
		num2 = num2*10 + x
	}
	return num1+num2
}