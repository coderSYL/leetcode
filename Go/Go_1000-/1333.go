// Go
// leetcode 1333
// https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
	res := make([]int, 0, 10)
	needVegan := veganFriendly == 1
	for _, restaurant := range restaurants {
		if needVegan && restaurant[2] == 0 { // 素食友好不符合
			continue
		}

		if maxPrice < restaurant[3] { // 超价格
			continue
		}

		if maxDistance < restaurant[4] { // 超距
			continue
		}

		res = append(res, -restaurant[1] * 100001 - restaurant[0])
	}

	sort.Ints(res)
	for i, _ := range res {
		res[i] = getId(res[i])
	}
	return res
}

func getId(x int) int {
	id := (-x) % 100001
	return id
}