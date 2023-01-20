// Go
// leetcode 1460
// https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/

func canBeEqual(target []int, arr []int) bool {
	cnt := make(map[int]int)
	for i := 0; i < len(target); i++ {
		cnt[target[i]]++
		cnt[arr[i]]--
	}
	for _, v := range cnt {
		if v != 0 {
			return false
		}
	}
	return true
}