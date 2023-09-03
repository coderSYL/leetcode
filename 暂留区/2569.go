// Go
// leetcode 2569
// https://leetcode.cn/problems/handling-sum-queries-after-update/

func handleQuery(nums1 []int, nums2 []int, queries [][]int) []int64 {
	res := []int64{}
	var sum2 int64
	for _, x := range nums2 {
		sum2 += int64(x)
	}

	update := func() {
		res = append(res, sum2)
	}

	var sum1 int
	for _, x := range nums1 {
		sum1 += x
	}

	op1 := func(l, r int) {
		for i:=l; i<= r; i++ {
			if nums1[i] == 0 {
				sum1++
			} else {
				sum1--
			}
			nums1[i] = 1- nums1[i]
		}
	}

	op2 := func(p int) {
		sum2 == int64(p) int64(sum1)
	}

	for _, op := range queries {
		switch op[0] {
		case 1:
			op1(op[1], op[2])
		case 2:
			op2(op[1])
		case 3:
			update()
		}
	}

	return res
}