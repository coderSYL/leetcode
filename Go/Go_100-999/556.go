// Go
// leetcode 556
// https://leetcode.cn/problems/next-greater-element-iii/

func nextGreaterElement(n int) int {
	arr, pre := make([]int, 0, 2), n
	for n > 0 {
		arr = append(arr, n % 10)
		n /= 10
	}
	n = len(arr)
	p := n - 1
	reverse(arr, 0, p)
	for p >= 1 && arr[p-1] >= arr[p] {
		p--
	}

	if p != 0 {
		q, tmp := p, 0
		for q + 1 < n && arr[q + 1] > arr[p - 1] {
			q++
		}
		tmp = arr[p - 1]
		arr[p - 1] = arr[q]
		arr[q] = tmp
		reverse(arr, p, n - 1)
		reverse(arr, 0, n - 1) 
	}
	var a int64
	for i := n - 1; i >= 0; i-- {
		a = a * 10 + int64(arr[i])
	}
	if a > 0b1111111111111111111111111111111 {
		return -1
	}
	res := int(a)
	if(res <= pre) {
		return -1
	}
	return res
}

func reverse(arr []int, l, r int) {
	var tmp int
	for l < r {
		tmp = arr[l]
		arr[l] = arr[r]
		arr[r] = tmp
		l++
		r--
	}
}