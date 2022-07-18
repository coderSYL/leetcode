// Go
// leetcode 1184
// https://leetcode.cn/problems/distance-between-bus-stops/

func distanceBetweenBusStops(distance []int, start int, destination int) int {
	if start == destination {
		return 0
	}

	if start > destination {
		start, destination = destination, start
	}

	sum, cur := 0, 0
	for i, d := range distance {
		sum += d
		if i >= start && i < destination {
			cur += d
		}
	}
	if cur * 2 > sum {
		cur = sum - cur
	}

	return cur
}