// Go
// leetcode 2103
// https://leetcode.cn/problems/rings-and-rods/

func countPoints(rings string) int {
	n := len(rings) / 2
	res := 0
	rod := make([]int, 10)
	getId := map[byte]int{
		'R':1,
		'G':2,
		'B':4,
	}
	for i:=0; i<n; i++ {
		id := getId[rings[2*i]]
		j := int(rings[2*i+1]-'0')
		rod[j] |= id
	}
	for i:=0; i<10; i++ {
		if rod[i] == 7 {
			res++
		}
	}
	return res
}