// Go
// leetcode 10
// https://leetcode.cn/problems/regular-expression-matching/

func isMatch(s string, p string) bool {
	sLength, pLength := len(s), len(p)
	dp := make([][]bool, sLength+1)
	for i := 0; i <= sLength; i++ {
		dp[i] = make([]bool, pLength+1)
	}
	dp[0][0] = true

	for i := 0; i < pLength; i++ { // fill dp[all][i+1]
		switch p[i] {
		case '.':
			for j := 0; j < sLength; j++ {
				dp[j+1][i+1] = dp[j][i]
			}
		case '*':
			if p[i-1] == '.' { // special case: .*
				j := 0
				for j <= sLength && !dp[j][i-1] {
					j++
				}
				for ; j <= sLength; j++ {
					dp[j][i+1] = true
				}
			} else { // letter + '*'
				for j := 0; j <= sLength; j++ {
					if dp[j][i-1] || (j > 0 && dp[j-1][i+1] && s[j-1] == p[i-1]) {
						dp[j][i+1] = true
					}
				}
			}
		default:
			for j := 0; j < sLength; j++ {
				dp[j+1][i+1] = s[j] == p[i] && dp[j][i]
			}
		}
	}

	return dp[sLength][pLength]
}