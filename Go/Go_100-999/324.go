// Go
// leetcode 324
// https://leetcode.cn/problems/wiggle-sort-ii/

func swap(arr []int, l, r int) {
	c := arr[r]
	arr[r] = arr[l]
	arr[l] = c
}

func qSelect(arr []int, l, r, k int) int {
	if l == r {
		return arr[l]
	}
	x, i, j := arr[(l+r) >> 1], l - 1, r + 1
	for i < j {
		for {
			i++
			if arr[i] >= x {
				break
			}
		}
		for {
			j--
			if arr[j] <= x {
				break
			}
		}
		if i < j {
			swap(arr, i, j)
		}
	}
	cnt := j - l + 1
	if k <= cnt {
		return qSelect(arr, l, j, k)
	}
	// else
	return qSelect(arr, j + 1, r, k - cnt)
}

func getIdx(x, n int) int {
	return (2 * x + 1) % (n | 1)
}

func wiggleSort(nums []int)  {
	n := len(nums)
	x := qSelect(nums, 0, n-1, (n+1) >> 1)
	l, r, loc := 0, n-1, 0
	for loc <= r {
		if nums[getIdx(loc, n)] > x {
			swap(nums, getIdx(loc, n), getIdx(l, n))
			loc++
			l++
		} else if nums[getIdx(loc, n)] < x {
			swap(nums, getIdx(loc, n), getIdx(r, n))
			r--
		} else {
        	loc++
        }
	}
}