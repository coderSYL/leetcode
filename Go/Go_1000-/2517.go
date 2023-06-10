// Go
// leetcode 2517
// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

func maximumTastiness(price []int, k int) (res int) {
    n := len(price)
    l, r := 0, 1000_000_000
    sort.Ints(price)
    var isOk func(int) bool
    isOk = func(x int) bool {
		cnt, last, p := 1, 0, 1
		for cnt < k && p < n && n-p >= k-cnt && price[last] + x <= 1000_000_000 {
			if price[p] - price[last] >= x {
				cnt++
				last = p
			}
			p++
		}
		if cnt >= k {
			return true
		}
        return false
    }

    for l < r {
        mid := (l+r)/2 + 1
        // fmt.Println(l,mid, r)
        if isOk(mid) {
            l = mid
        } else {
            r = mid-1
        }
    }
    return l
}

func max(a, b int) int {
	if a > b {
		return a 
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a 
	}
	return b
}