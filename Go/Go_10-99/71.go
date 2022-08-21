// Go
// leetcode 71
// https://leetcode-cn.com/problems/simplify-path/

func simplifyPath(path string) string {
	n := len(path)
	stk := []string{}
	for i := 0; i < n;  {
		for i < n && path[i] == '/' {
			i++
		}
		j := i
		for j < n && path[j] != '/' {
			j++
		}
        if i == j {
            break
        }
		cur := path[i : j]
        // fmt.Println(cur)
		switch cur {
		case ".":
		case "..":
			if len(stk) != 0 {
				stk = stk[0: len(stk) - 1]
			}
		default:
			stk = append(stk, cur)
		}
        i = j
	}

	if len(stk) == 0 {
		return "/"
	}

	res := ""
	for _, s := range stk {
		res += "/" + s
	}
	return res
}