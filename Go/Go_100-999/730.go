// Go
// leetcode 730
// https://leetcode.cn/problems/count-different-palindromic-subsequences/

func countPalindromicSubsequences(s string) int {
	MOD := int(1e9 + 7)
	n := len(s)
	f, L, R := make([][]int, n), make([]int, 4), make([]int, 4)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
	}
	for i := 0; i < 4; i++ {
		L[i] = -1
	}
	for i := n - 1; i >= 0; i-- {
		L[int(s[i]-'a')] = i
		for j := 0; j < 4; j++ {
			R[j] = -1
		}
		for j := i; j < n; j++ {
			R[int(s[j]-'a')] = j
			for k := 0; k < 4; k++ {
				if L[k] == -1 || R[k] == -1 {
					continue
				}
				l, r := L[k], R[k]
				if l == r {
					f[i][j] = (f[i][j] + 1) % MOD
				} else if l == r-1 {
					f[i][j] = (f[i][j] + 2) % MOD
				} else {
					f[i][j] = (f[i][j] + f[l+1][r-1] + 2) % MOD
				}
			}
		}
	}
	return f[0][n-1]
}