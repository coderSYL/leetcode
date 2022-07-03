// Go
// leetcode 1108
// https://leetcode.cn/problems/defanging-an-ip-address/

func defangIPaddr(address string) string {
	bs := make([]byte, 0, len(address))
	for _, c := range address {
		if c == '.' {
			bs = append(bs, '[', '.', ']')
		} else {
			bs = append(bs, byte(c))
		}
	}
	return string(bs)
}