// Go
// leetcode 1054
// https://leetcode.cn/problems/distant-barcodes/

func rearrangeBarcodes(barcodes []int) []int {
	n := len(barcodes)
	for i := 0; i < n-1; i++ {
		if barcodes[i] != barcodes[i+1] {
			continue
		}
		j := i + 2
		for j < n && barcodes[i] == barcodes[j] {
			j++
		}
		if j < n {
			barcodes[i+1], barcodes[j] = barcodes[j], barcodes[i+1]
		}
	}
	for i := n - 1; i > 0; i-- {
		if barcodes[i] != barcodes[i-1] {
			continue
		}
		j := i - 2
		for j >= 0 && barcodes[i] == barcodes[j] {
			j--
		}
		if j >= 0 {
			barcodes[i-1], barcodes[j] = barcodes[j], barcodes[i-1]
		}
	}
	return barcodes
}