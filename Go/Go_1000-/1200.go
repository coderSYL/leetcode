import "sort"

// Go
// leetcode 1200
// https://leetcode.cn/problems/minimum-absolute-difference/

func minimumAbsDifference(arr []int) (res [][]int) {
	sort.Ints(arr)
	n, cur, tmp := len(arr), 5000000, 0
	for i := 1; i < n; i++ {
		tmp = arr[i] - arr[i-1]
		if tmp < cur {
			res = [][]int{}
			res = append(res, []int{arr[i-1], arr[i]})
			cur = tmp
		} else if tmp == cur {
			res = append(res, []int{arr[i-1], arr[i]})
		}
	}
	return res
}