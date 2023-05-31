// Go
// leetcode 591
// https://leetcode.cn/problems/tag-validator/

func isValid(code string) bool {
	n := len(code)
	tagStk := []string{}
	if code[0] != '<' {
		return false
	}
	for i := 0; i < n; i++ {
		if len(tagStk) == 0 && i != 0 {
			return false
		}

		// find first <
		for i < n && code[i] != '<' {
			i++
		}

		// CDATA check
		if i+8 < n && code[i:i+9] == "<![CDATA[" {
			i += 9
			for i+2 < n && code[i:i+3] != "]]>" {
				i++
			}
			if i+2 >= n {
				return false
			}
			i += 2
			continue
		}

		if i+1 < n && code[i+1] == '/' { // 结束标签
			i += 2
			j := i
			for j < n && code[j] != '>' {
				if !isBigLetter(code[j]) || j-i > 8 {
					return false
				}
				j++
			}
			if j == n || i == j {
				return false
			}
			tag := code[i:j]
			if len(tagStk) == 0 || tagStk[len(tagStk)-1] != tag {
				return false
			}
			tagStk = tagStk[:len(tagStk)-1]
			i = j
			continue
		}

		// 起始标签
		i++
		j := i
		for j < n && code[j] != '>' {
			if !isBigLetter(code[j]) || j-i > 8 {
				return false
			}
			j++
		}
		if j == n || i == j {
			return false
		}
		tag := code[i:j]
		tagStk = append(tagStk, tag)
		i = j
	}
	return len(tagStk) == 0
}

func isBigLetter(b byte) bool {
	return b <= 'Z' && b >= 'A'
}