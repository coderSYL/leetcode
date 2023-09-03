// Go
// leetcode 771
// https://leetcode.cn/problems/jewels-and-stones/

func numJewelsInStones(jewels string, stones string) int {
	good := map[rune]bool{}
	for _, c := range jewels {
		good[c] = true
	}
	res := 0
	for _, c := range stones {
		_, ok := good[c]
		if ok {
			res++
		}
	}

	return res
}