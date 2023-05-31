// Go
// leetcode 1093
// https://leetcode.cn/problems/statistics-from-a-large-sample/

func sampleStats(count []int) []float64 {
	minimum, maximum, mode := 256, -1, 0
	sum, cnt := 0, 0
	for i, x := range count {
		if x == 0 {
			continue
		}
		minimum = min(i, minimum)
		maximum = max(i, maximum)
		sum += i * x
		cnt += x
		if x > count[mode] {
			mode = i
		}
	}

	// find median
	medianIndex := (cnt + 1) / 2
	need2nd := (cnt%2 == 0)
	var median float64
	for i := 0; i < len(count); i++ {
		medianIndex -= count[i]
		if medianIndex < 0 {
			if median > 0.1 {
				median = (median + float64(i)) / 2.0
			} else {
				median = float64(i)
			}
			break
		} else if medianIndex == 0 {
			if median > 0.1 {
				median = (median + float64(i)) / 2.0
			} else {
				median = float64(i)
			}
			if need2nd {
				need2nd = false
				medianIndex = 1
			} else {
				break
			}
		}
	}

	return []float64{float64(minimum), float64(maximum), float64(sum) / float64(cnt), median, float64(mode)}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}