// Go
// leetcode 2520
// https://leetcode.cn/problems/count-the-digits-that-divide-a-number/

func countDigits(num int) (res int) {
	x := num
	cnt := make([]int, 10)
	for x > 0 {
		cnt[x%10]++
		x /= 10
	}

	for i:=1; i<10; i++ {
		if num%i == 0 {
			res += cnt[i]
		}
	}

	return res
}