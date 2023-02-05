// Go
// leetcode 1109
// https://leetcode.cn/problems/corporate-flight-bookings/

func corpFlightBookings(bookings [][]int, n int) []int {
	res := make([]int, n)

	for _, order := range bookings {
		res[order[0]-1] += order[2]
		if order[1] < n {
			res[order[1]] -= order[2]
		}
	}

	for i := 1; i < n; i++ {
		res[i] += res[i-1]
	}
	return res
}