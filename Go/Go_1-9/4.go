// Go
// leetcode 4
// https://leetcode.cn/problems/median-of-two-sorted-arrays/
// 左右指针，略蛋疼

func findMedianSortedArrays(nums1 []int, nums2 []int) (res float64) {
	n1, n2 := len(nums1), len(nums2)
	pass := (len(nums1) + len(nums2) - 1) / 2
	l_pass, r_pass := 0, 0
	l1, l2 := 0, 0
	r1, r2 := n1 - 1, n2 - 1
	for l_pass < pass {
		if l1 > r1 {
			// l1 炸了
			l2 += pass - l_pass
			l_pass = pass
			continue
		}

		if l2 > r2 {
			l1 += pass - l_pass
			l_pass = pass
			continue
		}

		if nums1[l1] > nums2[l2] {
			l2++
		} else {
			l1++
		}
		l_pass++
	}

	for r_pass < pass {
		if l1 > r1 {
			r2 -= pass - r_pass
			r_pass = pass
			continue
		}

		if l2 > r2 {
			r1 -= pass - r_pass
			r_pass = pass
			continue
		}

		if nums1[r1] > nums2[r2] {
			r1--
		} else {
			r2--
		}
		r_pass++
	}
	// fmt.Println(l1,r1,l2,r2)
	if l1 < r1 {
		return (float64(nums1[l1]) + float64(nums1[r1])) / 2
	}

	if l2 < r2 {
		return (float64(nums2[l2]) + float64(nums2[r2])) / 2
	}

	if l1 == r1 {
		res = float64(nums1[l1])
	} else {
		res = float64(nums2[l2])
	}

	if l2 == r2 {
		res = (res + float64(nums2[l2])) / 2
	}

	return res
}