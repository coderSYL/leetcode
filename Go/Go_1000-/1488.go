// Go
// leetcode 1488
// https://leetcode.cn/problems/avoid-flood-in-the-city/

func avoidFlood(rains []int) []int {
	rainyDay := make(map[int]int)
	q := []int{} // always ascendent
	pre := []int64{}
	for i, lake := range rains {
		if lake == 0 {
			q = append(q, i)
			continue
		}
		day, ok := rainyDay[lake]
		if ok { // 之前下过雨
			goodIdx := search(q, day)
			if goodIdx == len(q) {
				return []int{}
			}
			goodDay := q[goodIdx]

			// del(q, goodIdx)
			q = append(q[:goodIdx], q[goodIdx+1:]...)

			pre = append(pre, int64(goodDay)*2000_000_000+int64(lake))
		}
		rainyDay[lake] = i
	}
	res := make([]int, len(rains))
	for i := range res {
		res[i] = -1
	}
	// fmt.Println(pre)
	// fmt.Println(q)
	for _, x := range pre {
		idx, lake := int(x/2000_000_000), int(x%2000_000_000)
		res[idx] = lake
	}
	for _, idx := range q {
		res[idx] = 1
	}
	return res
}

func search(arr []int, x int) int {
	// 返回 arr中比 x 大的 idx，如果全员小于 x，返回 len(arr)
	l, r := 0, len(arr)-1
	for l <= r {
		mid := (l + r) >> 1
		if arr[mid] < x {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return r + 1
}