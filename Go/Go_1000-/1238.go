// Go
// leetcode 1238
// https://leetcode.cn/problems/circular-permutation-in-binary-representation/

func circularPermutation(n int, start int) []int {
	size := 1 << n
	diff := findIdx(start)

	res := make([]int, size)
	for x := 0; x < size; x++ {
		idx := findIdx(x)
		res[(idx+size-diff)%size] = x
	}

	return res
}

func findIdx(x int) int {
	idx := 0
	for x > 0 {
		lb := lowBit(x)
		idx = 2*lb - 1 - idx
		x -= lb
	}
	return idx
}

func lowBit(x int) int {
	return x & -x
}

// // 第一版，未经抽象
// func circularPermutation(n int, start int) []int {
// 	size := 1 << n
// 	idx := 1
// 	helper := make([]int, size)
// 	helper[0] = 0
// 	head := 1
// 	for idx < size {
// 		for j := idx - 1; j >= 0; j-- {
// 			helper[idx] = helper[j] + head
// 			idx++
// 		}
// 		head <<= 1
// 	}
// 	for i, x := range helper {
// 		if x == start {
// 			idx = i
// 			break
// 		}
// 	}
// 	// 填装答案
// 	res := make([]int, size)
// 	for i := 0; i < size; i++ {
// 		res[i] = helper[(i+idx)%size]
// 	}
// 	return res
// }