// Go
// leetcode 1175
// https://leetcode.cn/problems/prime-arrangements/

const MOD = int64(1_000_000_007)

func numPrimeArrangements(n int) (ans int) {
	primeCnt, res := int64(1), int64(1)

	for i := 3; i <= n; i += 2 {
		if isPrime(i) {
			primeCnt++
		}
	}
	notPrime := int64(n) - primeCnt
	for primeCnt > 1 {
		res *= primeCnt
		res %= MOD
		primeCnt--
	}

	for notPrime > 1 {
		res *= notPrime
		res %= MOD
		notPrime--
	}
	ans = int(res)
	return ans
}

func isPrime(n int) bool {
	if n == 1 {
		return false
	}

	// even
	if n > 2 && n%2 == 0 {
		return false
	}

	l, r, mid := 0, n, 0
	if r >= 46340 {
		r = 46340
	}

	for l <= r {
		mid = (l + r) >> 1
		if mid*mid == n {
			return false
		} else if mid*mid > n {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}

	for i := 3; i < l; i += 2 {
		if n%i == 0 {
			return false
		}
	}

	return true
}