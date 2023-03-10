// Go
// leetcode 1487
// https://leetcode.cn/problems/making-file-names-unique/

func getFolderNames(names []string) (res []string) {
	exist := make(map[string]bool) // 记录是否出现过
	cnt := make(map[string]int)    // 记录出现次数-1

	for _, name := range names {
		idx := 0
		if exist[name] {
			cnt[name]++
			idx = cnt[name]
		}
		exist[name] = true
		if idx == 0 { // 没出现过
			res = append(res, name)
			continue
		}

		newName := name + "(" + strconv.Itoa(idx) + ")"
		for exist[newName] {
			idx++
			newName = name + "(" + strconv.Itoa(idx) + ")"
		}
		res = append(res, newName)
		exist[newName] = true
	}

	return res
}