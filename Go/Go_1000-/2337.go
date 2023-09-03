// Go
// leetcode 2337
// https://leetcode.cn/problems/move-pieces-to-obtain-a-string/

func canChange(start string, target string) bool {
	
	n := len(start)
	i, j:=0, 0
	for i<n && j<n {
		if start[i] == '_' {
			i++
			continue
		}
		if target[j] =='_' {
			j++
			continue
		}
		if start[i] != target[j] {
			return false
		}

		switch start[i] {
		case 'L':
			if i<j {
				return false
			}
		case 'R':
			if i>j {
				return false
			}
		}
		i++
		j++
	}
	for i<n {
		if start[i] != '_' {
			return false
		}
		i++
	}
	for j<n {
		if target[j] != '_' {
			return false
		}
		j++
	}
	return true
}