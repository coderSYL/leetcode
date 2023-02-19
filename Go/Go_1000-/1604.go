// Go
// leetcode 1604
// https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

// 将时间转换成一天中第多少分钟
func getInt(s string) int {
	mm := int(s[4]-'0') + 10*int(s[3]-'0')
	hh := int(s[1]-'0') + 10*int(s[0]-'0')
	return hh*60 + mm
}

func alertNames(keyName []string, keyTime []string) (res []string) {
	m := map[string][]int{}
	n := len(keyName)

	for i := 0; i < n; i++ {
		m[keyName[i]] = append(m[keyName[i]], getInt(keyTime[i]))
	}

	for name, arr := range m {
		sort.Ints(arr)
		sz, ok := len(arr), false
		// 检验该员工是否合格
		for i, j := 0, 0; j < sz; i++ {
			x := arr[i]
			for j < sz && arr[j]-x <= 60 {
				j++
			}
			if j-i >= 3 {
				ok = true
				break
			}
		}

		if ok {
			res = append(res, name)
		}
	}
	sort.Strings(res)
	return res
}