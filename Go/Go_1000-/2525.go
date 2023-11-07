// Go
// leetcode 2525
// https://leetcode.cn/problems/categorize-box-according-to-criteria/

func categorizeBox(length int, width int, height int, mass int) string {
	isBulky := false
	isHeavy := false
	volume := length * width * height
	if volume >= 1000_000_000 || length >= 10000 || width >= 10000 || height >= 10000 {
		isBulky = true
	}

	if mass >= 100 {
		isHeavy = true
	}

	if isBulky && isHeavy {
		return "Both"
	}

	if isBulky {
		return "Bulky"
	}

	if isHeavy {
		return "Heavy"
	}

	return "Neither"
}