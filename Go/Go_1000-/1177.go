// Go
// leetcode 1177
// https://leetcode.cn/problems/can-make-palindrome-from-substring/

func canMakePaliQueries(s string, queries [][]int) []bool {
	m := len(s)
	cnt := make([][26]int, m+1)
	for i:=0; i<m; i++ {
		u := int(s[i]-'a')
		for j:=0; j<26; j++ {
			cnt[i+1][j] = cnt[i][j]
		}
		cnt[i+1][u]++
	}
    // for i:=0; i<=m ;i++ {
    //     fmt.Println(cnt[i])
    // }
    
	check := func(a, b, c int) bool {
        
		if c >= 13 {
			return true
		}
		c *= 2
		if (b-a) % 2 == 0 {
			c++
		}
        // fmt.Println(">>", a, b)
		// arr := make([]int, 26)
		for i:=0; i<26 && c >= 0; i++ {
			cur := (cnt[b+1][i] - cnt[a][i]) % 2
			c -= cur
		}
        
		return c >= 0
	}

	n := len(queries)
	res := make([]bool, n)
	for i:=0; i<n; i++ {
		res[i] = check(queries[i][0], queries[i][1], queries[i][2])
	}
	return res
}