// Go
// leetcode 2178
// https://leetcode.cn/problems/maximum-split-of-positive-even-integers/

func maximumEvenSplit(finalSum int64) []int64 {
	if finalSum % 2 == 1 {
		return []int64{}
	}

	size := findSize(finalSum)
	remain := finalSum - evenSum(size)
	res := make([]int64, size)
	for i:=int64(1); i<size; i++ {
		res[i-1] = i*2
	}
	res[size-1] = size*2+remain
	return res
}


func evenSum(numsOfEven int64) int64 {
	return numsOfEven * (numsOfEven + 1)
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

func findSize(x int64) int64 {
	l, r := int64(1), min(int64(100_000), x)
	for l <= r {
		mid := l + (r-l)/2
		if evenSum(mid) <= x {
			l = mid+1
		} else {
			r = mid-1
		}
	}
	return l-1
}