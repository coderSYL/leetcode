// Go
// leetcode 2594
// https://leetcode.cn/problems/minimum-time-to-repair-cars/

func repairCars(ranks []int, cars int) int64 {
	// 时间 t，能修 cars 辆
	// 时间 t-1，只能修 cars-1 辆

	
	cars64 := int64(cars)
    sort.Ints(ranks)
	repairMen := len(ranks)
	one := cars/repairMen
	if one * repairMen < cars {
		one++
	}

	worstCap := ranks[repairMen-1]
	var l int64
	r := int64(worstCap) * int64(one) * int64(one)
	groupRepair := func(timeInMin int64) int64 {
		var res int64
		var last int64
		for _, cap := range ranks {
			last = repair(timeInMin, cap, last)
			res += last
		}
		return res
	}

	for l <= r {
		mid := l + (r-l)/2
		cur := groupRepair(mid)
		if cur >= cars64 {
			r = mid-1
		} else {
			l = mid+1
		}
	}
	return l
}

func repair(timeInMin int64, cap int, rVal int64) int64 {
	// 给一个能力为 cap 的技师 timeInMin分钟
	// 能修好多少辆车
	cap64 := int64(cap)
	l, r := int64(0), int64(rVal)
	if r <= 0 {
		r = 1000_000_000
	}
	upperBoundary := timeInMin / cap64
	
	for l<=r {
		mid := (l+r) / 2
		if mid * mid <= upperBoundary { // 修得完
			l = mid+1
		} else { // 修不完
			r = mid-1
		}
	}
	return r
}