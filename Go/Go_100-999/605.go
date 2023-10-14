// Go
// leetcode 605
// https://leetcode.cn/problems/can-place-flowers/

func canPlaceFlowers(flowerbed []int, n int) bool {
	zeroCnt := 1
	mx := 0
	for _, x := range flowerbed {
		switch x {
		case 0:
			zeroCnt++
		case 1:
			mx += (zeroCnt-1) / 2
			zeroCnt = 0
		}
	}
	mx += (zeroCnt) / 2
	return mx >= n
}