// Go
// leetcode interview05.02
// https://leetcode.cn/problems/bianry-number-to-string-lcci/

func printBin(num float64) string {
	resBytes := []byte{'0', '.'}
	for !isZeroFloat64(num) && len(resBytes) < 34 {
		if num >= 0.5 {
			num -= 0.5
			resBytes = append(resBytes, '1')
		} else {
			resBytes = append(resBytes, '0')
		}
		num *= 2
	}
	if len(resBytes) < 34 {
		return string(resBytes)
	}
	return "ERROR"
}

func isZeroFloat64(f float64) bool {
	if f < 0.0000001 && f > -0.0000001 {
		return true
	}
	return false
}