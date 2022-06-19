// Go
// leetcode 1089
// https://leetcode.cn/problems/duplicate-zeros/

func duplicateZeros(arr []int)  {
	// 统计
	cnt, diff, n := 0, 0, len(arr)
	for i := 0; i + cnt < n; i++ {
		if arr[i] == 0 {
			cnt++
		}
		if i + cnt == n {
			diff = 1
		}
	}
	// 预防类似 [1, ..., 1, 0] 这种情况
	if(diff == 1) {
		cnt--
		arr[n - 1] = 0
	}

	for i, j := n-1-diff, n-1-cnt-diff; j >= 0 && i != j; i-- {
		arr[i] = arr[j]
		if(arr[j] == 0) {
			i--
			arr[i] = 0
		}
        j--
	}
}