// Go
// leetcode 1921
// https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/

func eliminateMaximum(dist []int, speed []int) int {
	n := len(dist)
	// fmt.Println(dist)
	for i, d:=range dist {
		dist[i] = d/ speed[i]
		if dist[i] * speed[i] != d {
			dist[i]++
		}
	}
	sort.Ints(dist)
	// fmt.Println(dist)
	for i:= 0; i< n; i++ {
		if dist[i] <= i {
			return i
		}
	}
	return n
}