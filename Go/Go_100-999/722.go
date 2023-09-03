// Go
// leetcode 722
// https://leetcode.cn/problems/remove-comments/

func removeComments(source []string) []string {
	tmp := []byte{}
	res := []string{}
	updateRes := func() {
		if len(tmp) != 0 {
			res = append(res, string(tmp))
			tmp = tmp[:0]
		}
	}
	state := false // true means isInBlock
	outside:
	for _, s := range source {
		n := len(s)
		for i:=0; i<n-1; i++ {
			if state {
				if s[i] == '*' && s[i+1] == '/' {
					state = false
					i++
					if i == n-1 {
						updateRes()
						continue outside
					}
					continue
				}
			} else { // state = false
				if s[i] == '/' && s[i+1] == '/' {
					updateRes()
					continue outside
				}

				if s[i] =='/' && s[i+1] == '*' {
					state = true
					i++
					continue
				} else {
					tmp = append(tmp, s[i])
				}
			}
		}
		if state {
			continue
		}
		tmp = append(tmp, s[n-1])
		updateRes()
		tmp = tmp[:0]
	}

	return res
}