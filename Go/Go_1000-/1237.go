// Go
// leetcode 1237
// https://leetcode.cn/problems/find-positive-integer-solution-for-a-given-equation/

/**
 * This is the declaration of customFunction API.
 * @param  x    int
 * @param  x    int
 * @return 	    Returns f(x, y) for any given positive integers x and y.
 *			    Note that f(x, y) is increasing with respect to both x and y.
 *              i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

func findSolution(f func(int, int) int, z int) (res [][]int) {
	// find a max for x
	l, r := 1, z+1
	for l < r { // bisection
		mid := (l + r) >> 1
		if f(mid, 1) > z {
			r = mid - 1
		} else if f(mid, 1) < z {
			l = mid + 1
		} else {
			l = mid
			r = mid
		}
	}

	xUpperBoundary := r
	for x := 1; x <= xUpperBoundary; x++ { // x fixed, find good y for everyx
		l, r := 1, z+1
		for l <= r { // bisection
			mid := (l + r) >> 1
			if f(x, mid) > z {
				r = mid - 1
			} else if f(x, mid) < z {
				l = mid + 1
			} else {
				res = append(res, []int{x, mid})
				break
			}
		}
	}

	return res
}