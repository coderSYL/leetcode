// Go
// leetcode 781
// https://leetcode-cn.com/problems/rabbits-in-forest/

func numRabbits(answers []int) int {
	m := make(map[int]int)
	for _, v := range answers {
		m[v+1]++
	}

	res := 0
	for v, num := range m {
		res += ((num - 1 )/ v + 1) * v
	}

	return res
}