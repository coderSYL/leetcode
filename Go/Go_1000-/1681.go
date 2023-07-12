// Go
// leetcode 1681
// https://leetcode.cn/problems/minimum-incompatibility/

func minimumIncompatibility(nums []int, k int) int {
	n := len(nums)
	m := n/k

	cnt := make([]int, n+1)
	for _, x := range nums {
		cnt[x]++
		if cnt[x] > k {
			return -1
		}
	}
	sort.Ints(nums)
	memo := make([]int, (1<<n) * n)
	for i:=0; i<len(memo); i++ {
		memo[i] = -1
	}

	var dfs func(int, int) int
	dfs = func(mask, pre int) int {
		if mask == 0 {
			return 0
		}

		if memo[mask * n + pre] != -1 {
			return  memo[mask * n + pre]
		}

		cnt := popcnt(mask)
		rem := cnt % m
		res := 1<<10
		
		if rem == 0 { // 新子集的第一个
			res = dfs(mask ^ lowbit(mask), cntLeftZero(mask))
			for i:=0; i<n; i++ {
				memo[mask*n + i] = res
			}
			return res
		} else {
			if popcnt(mask>>(pre+1)) >= rem {
				for p := pre+1; p<n; p++ {
					if mask>>p & 1 != 0 && nums[p] > nums[pre] {
						res = min(res, dfs(mask ^ (1<<p), p) + nums[p] - nums[pre])
					}
				}
			}
			memo[mask*n + pre] = res
		}

		return res
	}
	return dfs(1<<n-1, 0)
}

func lowbit(x int) int {
	return x & -x
}

func popcnt(x int) int {
	res := 0
	for x > 0 {
		res += x%2
		x /= 2
	}
	return res
}

func cntLeftZero(x int) int {
	res := 0
	for x > 0 && x&1 == 0 {
		res++
		x /= 2
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}