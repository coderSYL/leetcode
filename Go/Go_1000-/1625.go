// Go
// leetcode 1625
// https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/

func findLexSmallestString(s string, a int, b int) string {
	n := len(s)
	bs2 := []byte(s + s)
	a_byte := byte(a)
	res := s

	op := func(idx int) { // b-manipulation
		idx %=2
		for i := idx; i < n; i+=2 {
			x := byte((bs2[i]-'0'+a_byte)%10 + '0')
            bs2[i] = x
		    bs2[i+n] = x
		}
		
	}

	limit := 9
	if b%n%2 == 1 {
		limit = 99
	}
	
	for i := 0; ; i++ { // a-manipulation
		// 录入
		startPoint := 0
		for { // b-manipulation
			s3 := string(bs2[startPoint : n+startPoint])
			if s3 < res {
				res = s3
			}
			startPoint = (startPoint + b) % n
			if startPoint == 0 { // end loop
				break
			}
		}
		if i >= limit {
			break
		}
		if i%10 == 9 {
			op(0)
		} else {
			op(1)
		}
	}
	return res
}