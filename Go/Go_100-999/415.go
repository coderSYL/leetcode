// Go
// leetcode 415
// https://leetcode.cn/problems/add-strings/

func addStrings(num1 string, num2 string) string {
	if len(num1) < len(num2) {
		num1, num2 = num2, num1
	}
	n1, n2 := len(num1), len(num2) // n1 >= n2

	arr := make([]byte, n1, n1 + 1)
	one := false
	var b1, b2 byte

	for i:=0; i<n1; i++ {
		b1 = num1[n1-i-1]
        if one {
            b1++
        }

		if i < n2 {
			b2 = num2[n2-i-1]
		} else if i == n2 {
			b2 = '0'
		}

		arr[i], one = add(b1, b2)
	}

	if one {
		arr = append(arr, '1')
	}

	l, r := 0, len(arr)-1
	for l<r {
		arr[l], arr[r] = arr[r], arr[l]
		l++
        r--
	}

	return string(arr)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func add(a, b byte) (res byte, one bool) {
	res = a - '0' + b
	if res > '9' {
		res -= 10
		one = true
	}
	return res, one
}