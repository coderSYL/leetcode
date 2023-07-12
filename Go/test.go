package main

import "fmt"

func main() {
	var a int
	a = power(8, 25)

	a = 3
	a = power(8, 2)
	fmt.Println(a)
}

func generateCode(arr []int) int64 {
	var res int64
	for i, x := range arr {
		u := int64(x) << (2 * i)
		res += u
	}
	return res
}

func decode(x int64) []int {
	res := make([]int, 25)
	for i := 0; i < 25; i++ {
		val := int((x >> (2 * i)) & 11)
		res[i] = val
	}
	return res
}

func printInLine(arr []int, lineSize int) {
	n := len(arr)
	turn := (n / lineSize) + 1
	fmt.Println(n, lineSize)
	for i := 0; i < turn; i++ {
		end := (i + 1) * lineSize
		if n < end {
			end = n
		}
		fmt.Println(arr[i*lineSize : end])
	}
}

func lowbit(x int) int {
	return x & -x
}

func power(a, b int) int {
	res := 1
	for b > 0 {
		res *= a
		b--
	}
	return res
}
