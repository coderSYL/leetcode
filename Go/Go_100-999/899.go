// Go
// leetcode 899
// https://leetcode.cn/problems/orderly-queue/

func orderlyQueue(s string, k int) string {
	n := len(s)

	if k == 1 {
		p := 0
		x, y := 0, 0
	outer:
		for i := 1; i < n; i++ {
			x, y = p, i

			for j := 0; j < n; j++ {
				if s[x] < s[y] {
					continue outer
				} else if s[x] > s[y] {
					p = i
					continue outer
				}
				x = (x + 1) % n
				y = (y + 1) % n
			}
		}

		if p == 0 {
			return s
		}

		return s[p : ] + s[0 : p]
	}

	tmp := []byte(s)
	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i] < tmp[j]
	})

	return string(tmp)
}