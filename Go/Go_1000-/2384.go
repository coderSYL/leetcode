// Go
// leetcode 2384
// https://leetcode.cn/problems/largest-palindromic-number/

func largestPalindromic(num string) string {
	// 统计每个数字出现次数
	cnt := make([]int , 10)
	for _, b := range num {
		cnt[int(b - '0')]++
	}

	// 成对的数录入
	tmp := make([]byte, 0, 4)
	for i := 9; i >= 0; i-- {
		if i == 0 && len(tmp) == 0 {
			continue
		}

		n := cnt[i] >> 1
		cnt[i] &= 1
		for n > 0 {
			tmp = append(tmp, byte(i + '0'))
			n--
		}
	}

	// 是否能在中间加一个数
	p := len(tmp) - 1
	for i := 9; i >= 0; i-- {
		if cnt[i] != 0 {
			tmp = append(tmp, byte(i + '0'))
			break
		}
	}

	// 填充尾巴
	for i := p; i >= 0; i-- {
		tmp = append(tmp, tmp[i])
	}

	return string(tmp)
}