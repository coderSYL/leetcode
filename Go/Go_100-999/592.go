import "fmt"

// Go
// leetcode 592
// https://leetcode.cn/problems/fraction-addition-and-subtraction/

// 最大公约数
func getGcd(a, b int) int {
	if b > a {
		a, b = b, a
	}

	if b == 0 {
		return a
	}

	return getGcd(b, a%b)
}

func fractionAddition(expression string) string {
	arr := make([]int, 0, 20)
	isNegative := false
	tmp := 0
	// 数据录入
	for _, c := range expression {
		switch c {
		case '/':
			if isNegative {
				tmp = -tmp
				isNegative = false
			}
			arr = append(arr, tmp)
			tmp = 0
		case '+':
			if isNegative {
				tmp = -tmp
			}
			arr = append(arr, tmp)
			tmp = 0
			isNegative = false
		case '-':
			if isNegative {
				tmp = -tmp
			}
			if tmp != 0 {
				arr = append(arr, tmp)
			}

			tmp = 0
			isNegative = true
		default:
			tmp = tmp*10 + int(c-'0')
		}
	}
	arr = append(arr, tmp)

	// 数据处理
	for len(arr) != 2 {
		// 运算
		tmp = getGcd(arr[1], arr[3])
		tmp = arr[1] * arr[3] / tmp
		arr[0] *= tmp / arr[1]
		arr[2] *= tmp / arr[3]
		arr[2] += arr[0]
		arr[3] = tmp
		tmp = arr[2]

		// 化简
		if tmp < 0 {
			tmp = -tmp
		}
		tmp = getGcd(tmp, arr[3])
		arr[2] /= tmp
		arr[3] /= tmp

		// 去掉头两位
		arr = arr[2:]
	}

	res := fmt.Sprint(arr[0], "/", arr[1])
	return res
}