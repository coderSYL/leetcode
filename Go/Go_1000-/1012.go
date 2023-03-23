// Go
// leetcode 1012
// https://leetcode.cn/problems/numbers-with-repeated-digits/

func numDupDigitsAtMostN(n int) int {
	length := getLength(n)
	nonRepeat := 0
	cur := 9
	for i := 1; i < length; i++ {
		nonRepeat += cur
		cur *= (10 - i)
	}

	used := make([]bool, 10)
	for i := length; i >= 0; i-- {
		if i == 0 {
			nonRepeat++
			break
		}
		num := getIth(n, i)

		x := 0
		for j := 0; j < num; j++ {
			if !used[j] {
				x++
			}
		}
		if i == length {
			x = num - 1
		}
		alreadyFixed := length - i + 1
		for alreadyFixed < length && x != 0 {
			x *= (10 - alreadyFixed)
			alreadyFixed++
		}
		nonRepeat += x

		if used[num] {
			break
		}
		used[num] = true
	}
	return n - nonRepeat
}

func getIth(n, i int) int {
	for i > 1 {
		i--
		n /= 10
	}
	return n % 10
}

func getLength(n int) (length int) {
	for n > 0 {
		n /= 10
		length++
	}
	return length
}
