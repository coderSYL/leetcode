// Go
// leetcode 88
// https://leetcode.cn/problems/merge-sorted-array/

func merge(nums1 []int, m int, nums2 []int, n int)  {
	idx := m+n-1
	i, j := m-1, n-1
	for i >= 0 && j >= 0 {
		if nums1[i] >= nums2[j] {
			nums1[idx] = nums1[i]
			idx--
			i--
			continue
		}
		// nums1[i] < nums2[j]
		nums1[idx] = nums2[j]
		idx--
		j--
	}
	for j >= 0 {
		nums1[j] = nums2[j]
		j--
	}
	return
}